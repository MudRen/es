// File: /d/noden/asterism/train_field.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����ѵ����");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�����ѵ������ĵط�,̧ͷ�Ϳ��Կ�����ʮֻʨ���������ڰ���С�
�������������ڽ��ܻ���ѵ��������ʨ���ޡ�
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
/*	
	set( "objects", ([
	        "trainer"   : MOB"trainer",	
	        "griffon#1" : MOB"griffon",
	        "griffon#2" : MOB"griffon",
	              ]) ) ;
*/	              
	set( "exits", ([
		"east"  : ASTR"patha",
		]) );
		
// #include "replace_room.h"
}

void reset()
{
      int i ;
      object mob,*clone ;
      clone = children(MOB"griffon") ;
      
      for(i=0;i<sizeof(clone);i++)
         { 
            if(environment(clone[i])==this_object())
                destruct(clone[i]) ;
           }
      if(mob = present("trainer")) destruct(mob) ;
      
      mob = new(MOB"trainer") ;
      mob->move(this_object()) ;         
      mob = new(MOB"griffon") ;
      mob->move(this_object()) ;      
      mob = new(MOB"griffon") ;
      mob->move(this_object()) ;
}



