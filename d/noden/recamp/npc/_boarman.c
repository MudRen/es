#include <mudlib.h>

void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 2 );
	ob->set_name( "boarman", "Ұ����" );
        ob->set_short( "Ұ����" );
	ob->set_long(
		"���....������Ұ���ͷ����������壬���ǳ���ʵ�ڱȰ����˳���\n"
		"����������֮�ᣬ��Ȼ���ð����˲�����һ������Ŀ�г�ª��\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 4 );
	ob->set_perm_stat( "con", 3 );
	ob->set( "max_hp", 50 );
	ob->set( "hit_points", 50 );
	ob->set_skill( "blunt", 20 );
	ob->set( "natural_armor_class", 10 );
	ob->set( "wealth/silver", 10 );
	ob->wield_weapon("/d/noden/recamp/obj/club");
}
