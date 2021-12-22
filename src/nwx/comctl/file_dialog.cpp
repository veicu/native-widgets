/**

    ...

*/


#include <Shlobj.h>


/**

*/
void get_existing_directory()
{
    TCHAR szDir[MAX_PATH];
    BROWSEINFO bInfo;
    bInfo.hwndOwner = NULL;
    bInfo.pidlRoot = NULL;
    bInfo.pszDisplayName = szDir; // Address of a buffer to receive the display name of the folder selected by the user
    bInfo.lpszTitle = L"Please, select a folder"; // Title of the dialog
    bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_NEWDIALOGSTYLE;// 0 ;
    bInfo.lpfn = NULL;
    bInfo.lParam = 0;
    bInfo.iImage = -1;

    LPITEMIDLIST lpItem = SHBrowseForFolder( &bInfo);

    if( lpItem != NULL )
    {
        SHGetPathFromIDList( lpItem, szDir );
        //......
    }
}
