
#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����");
        set_long( 
@LONG
���ˮ�� (well) ������ճ���������Ϊ����ˮԴ�أ�ƽʱ�����ﶼ��������
Ѳ��һ�������Ҷ�����ά�޵Ĺ���������ˮ���ܵ���Ⱦ�����ԣ���ھ���������Ȼ
�Ͼɣ���Ȼ������Ǭ���Ĺ�ˮ�����Ա߲�ʱ�и�Ů��ϴ���������ҳ������Ҷ̵ģ�
˵��������Դ����д�����ʲ����Ҫ����ϢҲ˵��������·�������������ꣻ�ϡ�
������һ��ǽ��
LONG);
    set( "light",1);
    set("exits",([
       "north":LAKE"village10",
        "east":LAKE"village11"
    ]) );   
    set("c_item_desc",([
      "well":"һ���峺��ˮ���������й�������ȥ (jump) �ĳ嶯��\n",
    ]) );         
    set("objects",([
       "woman#1":LMONSTER"woman",
       "woman#2":LMONSTER"woman",
       "woman#3":LMONSTER"woman",
    ]) );
    ::reset();
}
void init()
{
    add_action("do_jump","jump");
}
int do_jump(string arg)
{
    if ( ! arg || arg !="well" )
       return 0;
    write("�������ԥ���ѹ������һ��!\n\nֻ������һ����������������� ...\n\n\n");
    this_player()->move_player(LAKE"village5",({
       "%s�ѹ��·�����һ�� ��\n",
       "%s�ӵ��µĳ�ˮ������.\n"}),"");
    return 1;
}