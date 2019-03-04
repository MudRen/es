#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "east9", "��������" );
	set_long(@C_LONG
��������һ�������ķ���,��Ϊ���ﳤ��Ƿȱ���������,�������йɻ�֮��ȥ
�ķ�ùζ��������ûʲ�����,�ն�����,ǽ����ֻ�м���������Ļ��, ����Ҳû
ʲ��ӡ֮��Ķ���,�Ͼ��������������
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "north":DBEGGAR"east10.c",
                      "south":DBEGGAR"east8.c"
	]) );
        set("objects",([
                      "guard1":DMONSTER"jail_guard",
                      "guard2":DMONSTER"jail_guard",
                      "guard3":DMONSTER"jail_guard",
                      "guard4":DMONSTER"jail_guard",
                      "guard5":DMONSTER"jail_guard",
                      "guard6":DMONSTER"jail_guard",
                      "guard7":DMONSTER"jail_guard",
                      "guard8":DMONSTER"jail_guard",
                      "guard9":DMONSTER"jail_guard",
                     "guard10":DMONSTER"jail_guard", 
        ]) );
        set("pre_exit_func",([
                "north":"do_show"]));
     reset();
}
void init()
{ 
   add_action("do_show","show"); 
}

int do_show( string arg )
{
   if( !present("jail guard"))
      return 0;
    
   if ( !arg || arg != "password" ){
      write(@C_LONG
����������ס���������
����˵��˵��:������������ø��ҿ� ( show password ),�����ҾͿ��������ȥ��
C_LONG
           );
      return 1;        
   }
   
   if ( present("password",this_player()) ){
      write(@C_LONG
����˵��:��,����Թ�ȥ��,������Ҫ�����¡�
C_LONG
            );
      this_player()->move_player(DBEGGAR"east10");
      return 1;
   }      
}