#ifndef NWX_PROPERTY
#define NWX_PROPERTY


namespace nwx
{
	template <typename PropertyT>
	class t_property
	{
	public:
		typedef PropertyT property_type;

		/**
		Standard constructor.
		*/
		t_property() : m_value ( 0 )
		{
			// nothing to do ...
		}

		/**
		Extended constructor.
		*/
		explicit t_property( const property_type other_value ): m_value( other_value )
		{
			// nothing to do ...
		}

		/*
		Copy constuctor.
		*/
		t_property( const t_property& other ) : m_value( other.m_value )
		{
			// nothing to do ...
		}

		/**
		Assignment operator.
		*/
		t_property& operator=( const t_property& other )
		{
			if( this != &other )
			{
				m_value = other.m_value;
			}
			return *this;
		}

		/**
		Assignment operator.
		*/
		t_property& operator=( property_type value )
		{
			m_value = value;
			return *this;
		}

		/**
		Set.
		*/
		void handle( const property_type other_value )
		{
			m_value = other_value;
		}

		/**
		Get.
		*/
		property_type handle()
		{
			return m_value;
		}

		/**
		Get.
		*/
		property_type handle() const
		{
			return m_value;
		}

		/**

		*/
		const property_type operator()()
		{
			return m_value;
		}

		/**

		*/
		const property_type operator()() const
		{
			return m_value;
		}

		/**

		*/
		const property_type& operator*() const
		{
			return m_value;
		}

	private:
		property_type m_value;
	};


	//
	// Some typedefs
	//

	typedef t_property<bool> bool_property;
	typedef t_property<int> int_property;
}


#endif // NWX_PROPERTY
