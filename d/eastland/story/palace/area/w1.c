#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("�춼�������");
	set_long( @LONG
������֮�����춼�������࣬������ԭ������Ƭ�侫���񽨳ɵģ�������
���ؼѣ�����������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲���
ת��⣻��ƫ�����ʱڣ����һ���Ŵ���������֮����������Ȼ�ռ������ȴ
�淢�Ե�ׯ��¡�أ�������ǧ��
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"center",
           "west" : SPALACE"palace1",
          "north" : SPALACE"n1w1",
          "south" : SPALACE"s1w1",
        ]) );
        create_door( "west","east" ,([
          "keyword" : ({ "jade door", "door" }),
          "name" : "jade door",
          "c_name" : "����",
          "c_desc" : "һ���������Ĵ��ţ����������������ȸ����\n",
          "status" : "closed"
        ]) );
        set("pre_exit_func",([
          "west":"can_pass"]));
        reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1; 
   return 0;
}   
