
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "Dwarf poet", "����ʫ��" );
	add ("id", ({ "poet","dwarf" }) );
	set_short( "Dwarf writer", "����ʫ��" );
	set_long(@DESC
һ������ʫ��,������Ѱ��д�������(afflatus)��ɢ����С·��,Ϊ��Ѱ��
������Ѿ��ü���û��˯����.
DESC
     );
    set( "alignment", -100 );
    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(4,2,6);
	set_natural_armor(26,0);
    set ("weight", 300);
    set ("chat_chance", 25);
    set ("chat_output", ({
            "������˵:����һ���õ���Ʒ��Ҫһ���õ����,��������ȥ��Ѱ�����?\n",
	    }) );
	set ( "inquiry",([
	      "afflatus":"@@ask_afflatus",
	      "muse":"@@ask_muse",
	      "queen":"@@ask_queen",
	      ]) );
	wield_weapon(Weapon"/dagger03");
    equip_armor(Armour"/cloth04");
}

void ask_afflatus(object who)
{
     who->set_explore("deathland#38");
     tell_object(who,
	"����д�˵����˼(Muse)Ȫ��Ȫˮ�Ļ�,�����ܰ����һ��ҵ����.\n");  
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
һ��ʫ��֮Ȫ,��˵��ȷ��λ�������������ص����,����
��ϸ��λ��û�м�����֪��,
����,�����峤��֪��,���Ǹ������ǻ۵���
MSG1
                 );
}

void ask_queen(object who)
{
     tell_object(who,"�����Ļʺ�, ȫ��������Ϊ�����ڵ�����\n");
}
