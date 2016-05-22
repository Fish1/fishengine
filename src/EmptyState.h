#ifndef FE_EMPTYSTATE 
#define	FE_EMPTYSTATE 

#include "State.h"

namespace fe
{
	class EmptyState : public State 
	{
	private:
		
		EmptyState();

	public:

		static EmptyState &instance()
		{
			static EmptyState instance;

			return instance;	
		}

		void enter(fe::Core &core);

		void reactEvent(fe::Core &core);

		void execute(fe::Core &core);
		
		void exit(fe::Core &core);
	};
}

#endif
