/**

    ...

*/


#include "combo_box.hpp"
#include <nwx/gui/window_private.hpp>
#include <nwx/core/wstring.hpp>
#include <nwx/core/use_windows.hpp>


namespace nwx
{
namespace comctl
{


/**
    Constructor.
*/
combo_box::combo_box( nwx::gui::window* parent ) : control( parent )
{
    initialize();
}

/**
    Constructor.
*/
combo_box::combo_box( nwx::gui::window* parent, int x, int y, int width, int height ) : control( parent, x, y, width, height )
{
    initialize();
}

/**
    Add item, returns on success index of added item else -1.
*/
int combo_box::add_item( const std::string& txt )
{
    nwx::core::wstring ws( txt );
    return static_cast<int>( ::SendMessage( d->window_resource, CB_ADDSTRING, 0, LPARAM( ws.lpcwstr() ) ) );
}

/**
    Insert item at given index, returns on success index of inserted item else -1..
*/
int combo_box::insert_item( int index, const std::string& txt )
{
    nwx::core::wstring ws( txt );
    return static_cast<int>( ::SendMessage( d->window_resource, CB_INSERTSTRING, index, LPARAM( ws.lpcwstr() ) ) );
}

/**
    Remove item at given index.
*/
void combo_box::remove_item( int index )
{
    ::SendMessage( d->window_resource, CB_DELETESTRING, index, 0 );
}

/**
    Remove all items.
*/
void combo_box::remove_all_items()
{
    ::SendMessage( d->window_resource, CB_RESETCONTENT, 0, 0 );
}

/**
    Get number of items.
*/
int combo_box::item_count()
{
    return static_cast<int>( ::SendMessage( d->window_resource, CB_GETCOUNT, 0, 0 ) );
}

/**
    Get the item's text.
*/
std::string combo_box::item_text( int index )
{
    std::string txt;

    int len = static_cast<int>( ::SendMessage( d->window_resource, CB_GETLBTEXTLEN, index, 0 ) );
    if( len > 0 )
    {
        wchar_t* wchar;
        wchar = new wchar_t[ static_cast<size_t>( len ) + 1 ];
        ::SendMessage( d->window_resource, CB_GETLBTEXT, index, LPARAM( wchar ) );
        txt = nwx::core::wstring::utf8_encode( wchar );
        delete[] wchar;
    }

    return txt;
}

/**
    Get the index of currently selected item.
*/
int combo_box::current_item()
{
    int index = static_cast<int>( ::SendMessage( d->window_resource, CB_GETCURSEL, 0, 0 ) );
    if (index != CB_ERR && index >= 0)
        return index;
    else
        return index;
}

/**
    Set the currently selected item by index.
*/
void combo_box::current_item( int index )
{
    ::SendMessage( d->window_resource, CB_SETCURSEL, index, 0 );
}

/**
    Set the currently selected item by which's text begins with the given text.
*/
void combo_box::current_item( const std::string& txt )
{
    nwx::core::wstring ws( txt );
    ::SendMessage( d->window_resource, CB_SELECTSTRING, WPARAM( -1 ), LPARAM( ws.lpcwstr() ) );
}

/**

*/
void combo_box::on_command( int id, int code )
{
    switch( code )
    {
    case CBN_DBLCLK:
        break;

    case CBN_SELCHANGE:
        {
            selection_changed( current_item() );
        }
        break;

    case CBN_EDITCHANGE:
        break;

    default:
        break;
    }
}

/**

*/
void combo_box::initialize()
{
    //do_command( true );

    nwx::gui::window_info wi;
    wi.class_name = "ComboBox";
    wi.create_window_ext_style = WS_EX_CLIENTEDGE;
    wi.create_window_reg_style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL| CBS_HASSTRINGS | CBS_AUTOHSCROLL | CBS_DROPDOWNLIST;

    d->create_window( wi );
    use_default_font();
}


}
}
