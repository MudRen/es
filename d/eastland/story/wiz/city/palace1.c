#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ʹ����");
	set_long( @LONG
�������ڻʹ�����ϣ���ʱ�������������������濴�غ����ʹ��İ�ȫ�����
���������ɵģ����ϵĻ��ƶ˵����廨����������Ŀ������Ͼ����Ŀ�����Ի���ֲ
��һ���ŵĻ�����ľ���ǻ��������˱ǣ�����ҷ��������Ŀ���������ǰ�治Զ��
���ǻʹ��ˡ�
LONG
	);
        set("light",1);
        set("pre_exit_func",([
           "north":"can_pass"]));
	set( "exits", ([ 
           "north" : SCITY"palace2",
           "south" : SCITY"center"
        ]) );
	set( "objects", ([
	   "bodyguard#1" : SWMOB"wiz_bodyguard1",
           "bodyguard#2" : SWMOB"wiz_bodyguard1",
	   "bodyguard#3" : SWMOB"wiz_bodyguard1",
               "captain" : SWMOB"wiz_captain1",
	]) );
	reset();
}
int can_pass()
{
    object guard;
    if ( !guard=present("bodyguard",this_object()) ) return 0;
    if ( !present("archmaster's mark",this_player()) ) {
       write(sprintf(
          "\n%s˵���������֮���������˵�һ�ɲ�׼������(entrance_palace)\n	      �����ȿ�첽�г�ȥ��\n\n",
           guard->query("c_name")));
       return 1;       
    }
    write(@LONG

���ҡ��ڵ��ֳ����ƽ���ʹ���������������͵͵����һ���ֳ��ֳ���ƨ����

    
LONG    
   );
   return 0; 
}