inherit MONSTER;
#include "../hawk.h"

void create()
{
        ::create();
        set_level(15);
	set_name( "crying girl", "��������Ů" );
	add("id", ({"girl","crying girl"}) );
	set_short( "��������Ů" );
        set_long(
                "�㿴��һ����������Ů�������ĵĿ���(crying).....\n"
        );
        set( "gender", "female" );
        set( "race", "imp" );
        set( "alignment", 200 );
	set( "no_attack",1);
	set( "inquiry",([
		"crying":"@@ask_crying",
			]) );
        set_natural_armor( 11, 6 );
        set_natural_weapon( 11 , 11 , 5 );
        set_perm_stat( "dex", 5 );
        set( "wealth/silver", 70 );
}

void init()
{
	add_action("to_go","go");
}

int to_go()
{
	if ((int)this_player()->query_level() < 13) return 0;
		tell_object(this_player(),@LONG
��������Ů������������ס������½ǣ���������Ҫ��İ�����
LONG
		);
		command("tackle "+(string)this_player()->query("name") );
		return 1;
}


int ask_crying()
{
	object obj;
	if ((int)this_player()->query_level() < 13)
	{
		tell_object(this_player(),@LONG
��Ů̧ͷ˵��: С���ѣ�ǰ�滵�˺ܶ࣬�����Ļ�����Ҫ����ǰ���ޡ�
LONG
		);	
		return 1;
	}
	tell_object(this_player(),@LONG
��Ů��Ȼ̧ͷ���ſ�Ѫ���ܵĴ��죬��е�:
    �۹���������Ϊ���ڿ���������̫�����ˡ�
ֻ��һ����ɫ��Ӱ���켲�壬��Ů��ת��һ���һ���׶�Ĵ��ߡ�
LONG
	);		
	obj = new(MOB"widow_serpent");
	obj->move(HAWK"room1-1");
	this_object()->remove();
}
