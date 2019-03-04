// Modified by Yueh to let lich teach magic, in 1995/3/8
#include "/d/noden/forest/ruin/ruin.h"
#include "/d/mage/mage.h"
inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set("light",0);
	set_short("ͨ��");
	set_long(@CLong
ͨ����ͻȻ���������ˡ�ʯ�顢������������·��ȫ��ס, ʹ���޷�
�ټ���ǰ����
CLong
	);
	set("exits",([
		"south"	: RUIN"tunnel_4",
	]));
	set("objects", ([
		"lich"   : MOB"lich",
		"daemon" : MOB"great_demon",
	]) );
	set( "item_func", (["index" : "view" ]) );
	set_spells( ([
		"heart-griping"       : ({ "black-magic", 40, 4, 10, 200 }),
		"heart-protect-shield"  : ({ "black-magic", 40, 3, 15, 160 }),
	]) );
	reset();
}

void init()
{
	add_action("do_dig","dig");
	add_action("do_raise","raise");
	add_action("do_study","study");
}

int do_dig()
{
	write("�����������ڱ������ʯ, ����̮���ĳ���̫����, ����ͷ��װ�����ڲ����ġ�\n");
	tell_room(this_object(), 
		this_player()->query("c_name") + "����ȥ���ڱ������ʯ, ����û��þͷ�����\n"
		,this_player() );
	return 1;
}

int checking(object who )
{
	string class1;
	int ali;
	class1 = (string)this_player()->query("class");
	ali = (int)this_player()->query("alignment");
	if (!present("lich") || ((int) who->query_quest_level("wanfu")) < 1 || ali > -200) 
		return 1;
	if( class1=="mage" || class1=="necromancer" || class1=="sage" )
		return 0;
	else return 1;
}

int do_raise(string arg)
{
	if (checking(this_player()) == 0)
	{
		::do_raise(arg);
		return 1;
	}
	else {
		printf("�����ʲ�᣿\n");
		return 1;
	}
}

int do_study(string arg)
{
	if (checking(this_player()) == 0)
	{
		::do_study(arg);
		return 1;
	}
	else {
		printf("�����ʲ�᣿\n");
		return 1;
	}
}

void view()
{
        mapping spells;
        string *s;
        int i;
	if (checking(this_player()) == 0)
	{
        printf( "%-34s  %-15s  %-8s  %-8s\n",
                 "��������", "��������",
                 "���輼��" ,  "�����");
        write( "=======================================================================\n");
        spells = query_spells();
        s = keys(spells);
        for( i=0; i<sizeof(s); i++ ) {
                printf( "%-34s  %-15s  %5d     %6d\n",
                         to_chinese(s[i]) + " (" + s[i] + ")",
                         to_chinese(spells[s[i]][0]),
                        spells[s[i]][1], spells[s[i]][2] );
        }
        write( "=======================================================================\n");

	}
	else {
		printf("�����ʲ�᣿\n");
	}

}
