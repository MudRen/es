
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
	object helmet,boots,lance,amulet,leggings,plate,cloak;

	::create();
	set_level(14);
	set_name( "daemonic fighter", "��ħսʿ" );
	add ("id", ({ "fighter", "daemon" }) );
   set_short( "��ħսʿ" );
	set("unit","λ");
   set_long(
	   " ���ǵ���ħ���־����ʱ�������Թ��Ĳд��ħ���ˣ���һλ���µ�սʿ��\n"
	);
	set("alignment",-1000);
	set("wealth/gold",20);
	set_perm_stat("str", 17);
	set_perm_stat("dex", 18);
	set_perm_stat("kar",10);
	set_natural_weapon( 10, 6, 8 );
	set ("natural_armor_class", 20);
	set ("gender", "male");
	set ("race", "daemon");
	set( "tactic_func", "my_tactic" );
	set_c_verbs(({"��%s��%��ȥ","��%sʹ����ɱһ����%s����","��%s��%s��ȥ"}));
	set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
       
	set_skill("parry", 75);
	set_skill("thrusting", 75);

	set("natural_defense_bonus",10);
	wield_weapon(LWEAPON"daemon_lance");      
	equip_armor(LARMOR"daemon_boots");
	equip_armor(LARMOR"daemon_amulet");
	equip_armor(LARMOR"daemon_leggings");
	equip_armor(LARMOR"daemon_plate");
	equip_armor(LARMOR"daemon_cloak");
	equip_armor(LARMOR"daemon_helmet");
}


int my_tactic()
{
	object *victim;

	if( random(20)>2 || !(victim= query_attackers()) ) return 0;
   tell_room( environment(),
		"\n��ħսʿ�������µĺ������������һ����������Կ�ʼ���� ....\n"
           "\n�������ǰһ��, ĳ�����ص����������������, ʹ��ʹ�಻��!\n\n",
		this_object() );
	victim->receive_special_damage( "evil", 40 );
	return 1;
}
