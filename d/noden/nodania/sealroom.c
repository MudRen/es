#include <mudlib.h>

inherit ROOM;

void create()
{
	set_short("��ӡ֮��");
	set_long( @LONG_DESCRIPTION
����������һ���İ��Ĵ������������ǰ��Ҳ���Ǵ������ϱߣ�һ��޴�
�ľ���(rock)��ס�������������ϱߣ�����ϸһ���������ƺ�����Ǳ�������
���������ҽ���ģ�����û���κδ�����ֻ�ж������Ż�ѷ�����΢������
������ע�⵽����������������һ��ʯ��(tablet)��
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
	     "north" : "/d/noden/nodania/tower1" ]) );
	set( "item_desc", ([ 
	     "tablet" : @LONG_TEXT
ʯ����ֻ�ж̶̵�һ����:

    �˵ط�ӡ��ͨ���״��(Mydarr)֮ĹѨ����ڣ��κ��˲�׼���롣
LONG_TEXT
, 
		"rock" : "�����ҿ���������൱��Զ�ˣ��ڻ�����ҫ�³��ֳ�һ��������Ѫ��ɫ��\n" ]) );
	reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string str)
{
    if (!str)
	return notify_fail("������ʲ�ᶫ��?\n");
    if (str == "tablet")
    {
	tell_object(this_player(), "���ʯ���ƺ���ĳ�ֿ��� ....\n");
	return 1;
    }
    if (str == "rock")
    {
	tell_object(this_player(), "����ˣ��㲻�����ƶ������ҵ� ....\n");
	return 1;
    }
}

int to_push(string str)
{
    object p;
    p = this_player();

    if (!str)
	return notify_fail("�����ƶ�ʲ�ᶫ��?\n");
    if (str != "tablet")
	return notify_fail("���þ��˳��̵������������Ʋ�������\n");
    if ((int)p->query_perm_stat("str") < 12)
	return notify_fail("̫���ˣ����Ʋ��� ....\n");
    else
    {
	tell_object(p, @FACE
�����ƿ�ʯ������һɲ�ǣ����Һ�Ȼ������һ�������Ĺ���!!

����ͻȻ�������������ͷ����������������!!

(������һ���µĵط�)

FACE
		   );
	tell_room(environment(p), sprintf("������һ�������ĲҽУ���ͷһ��%s�Ѿ���֪�����ˡ�\n", p->query("c_name")), ({p}));
     p->move_player("/d/noden/ruin/room/en0","SNEAK");
    }
    return 1;
}

