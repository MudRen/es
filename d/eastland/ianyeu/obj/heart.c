#include <mudlib.h>

inherit OBJECT;

int cutted;

void create()
{
    set_name( "wolf heart", "����" );
    add( "id", ({ "heart" }) );
    set_short( "����" );
    set( "unit", "��" );
	set("long","@@query_c_long");
    set( "weight", 10 );
    cutted = 0;
}

string query_c_long()
{
    if( cutted )
        return "����һ�ű��г�һ��ϡ�õ�����, ��Խ��Խ�ж��ġ�\n";
	else
        return "����һ��Ѫ���ܵ�����, �ƺ�ûʲ�����ü�ֵ��\n";
}

int query_cutted() { return cutted; }

void init()
{
    add_action( "cut_heart", "cut" );
}

int cut_heart(string arg)
{
    object cleaver;

    if( !arg || ( arg!="heart" && arg!="wolf heart") )
        return notify_fail("��Ҫ��ʲ�ᶫ����\n");
    if( cutted )
        return notify_fail("������Ѿ����й��ˡ�\n");

    cleaver = present("cleaver",this_player());

    if( !present("cleaver",this_player()) )
        return notify_fail("������Ұ��ʵ��ĵ���������\n");

    cutted = 1;
    write("���������������Ĵ��˿顣\n");
	return 1;
}


