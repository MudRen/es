#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��԰");
	set_long( @C_LONG_DESCRIPTION
������һ�����Ž��صĻ�԰�������зǳ�����滨��ݣ���֣�󻧴����������ֲ��
���ģ�������һ�����˸ߵ�ʳ������ÿ��Ҫ����һֻ����Ҳ�����괿��õ����˵��԰��
��ʦ�������ĵĽ���������Ҳ��һ����Ȫ(fountain)��
C_LONG_DESCRIPTION
	);
set("item_desc",([
    "fountain":"����һ��Ǭ��\����Ȫ��\n"]));
	
	set("objects",([
	    "woman1":"/d/noden/nodania/monster/gardener"
	    ]));
	set( "light", 1 );
	set( "exits", ([
	    "west" : Lcave"cave29"
	]) );
	reset();
}

void init()
{
    add_action("do_enter","enter");
 }
 
int do_enter(string arg)
{ 
 if (!arg || arg!="fountain") return 0;
 tell_room(environment(this_player()),
         this_player()->query("c_name")+"������Ȫ��\n",this_player() );
 this_player()->move_player(Lcave"cave31","SNEAK");
 return 1;
 }
