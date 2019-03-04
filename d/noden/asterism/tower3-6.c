// File: /d/noden/asterism/tower3-6.c

#include "asterism.h"////#pragma save_binary

inherit ROOM;

void create()
{
        object mob ; 	
	::create();        
        
	set_short("�ؾ������Ķ�¥");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����еؾ���������㡣���˺Ͱ�����Ϊ��Ƭ���ر�����
���˽���������һ����ۺ�ΰ��ס����������ܵ�ǽ�,����ʽ��ɫ�ı�ʯ���
������ͷס�����һ����Ǵ�˵�еؾ�����Ժ��ϯ��ס����
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down": ASTR"tower3-5",
		]) );
	set("pre_exit_func",(["down" : "check_cast" ]) ) ;
	
        set("no_embattle",1) ;
	set("cast_block",0) ;  

        mob = new(MOB"gnome_archelder") ;
        mob -> move( this_object() ) ;

}

int clean_up() { return 0; }

int check_cast()
{  
     object victim,elder ;
     int aa ;
          
     elder = present("archelder") ;
     if(!elder) return 0 ;
     aa = elder->query_temp("cast_busy");

     if( aa && (int)this_player()->query_temp("once_k_archelder") )
       {
//         tell_room(this_object(),"been blocked.\n",) ;
         write(
               "һ�����⵲ס���ȥ·���㱻�����ص���������������\n"
                ) ;
         return 1 ;
        }
     return 0 ;
}

