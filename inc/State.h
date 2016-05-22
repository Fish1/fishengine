#ifndef FE_STATE
#define FE_STATE

namespace fe
{
	class Core;

	class State
	{

	protected:
		
		State()
		{

		}
	 
	public:

		virtual void enter(Core &core) = 0;

		virtual void reactEvent(Core &core) = 0;

		virtual void execute(Core &core) = 0;
			
		virtual void exit(Core &core) = 0;
	};
}	

#endif
