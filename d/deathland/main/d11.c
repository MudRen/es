
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("��Ԩ�Ϸ�");
set("long",@Long_description
����������ȥ,��һ���ǳ���,�ַǳ������Ԩ���������ǰ,�ƺ����˾�������
��ͨ�����������.��������������(tents),��������������һ��Ӫ��(campfire)��
����
Long_description
	);
set("exits",(["west":Deathland"/main/d9",
              ]));
set("item_desc",([
    "campfire":"һ���ѱ�Ϩ���Ӫ��.\n",
    "tents":"�����ܴ������,����һ�������ǳ�����,��������ӭ��ÿ���˽�������.\n"
               ]) );

}

void init()
{
 add_action("to_enter","enter");

}

int to_enter(string str)
{
    if (!str||str!="tent") return 0;
    this_player()->move_player(Deathland"/main/shop",({
    "%s����������.\n",
    "%s���������˽���.\n"}),"");
    write("������߽���һ���̵�.\n");
    return 1;
}
