#include "../island.h"

inherit IWAR"i_warvalue";

void create()
{
	::create();
	set_level(10);
	set_name( "Light teeth", "����" );
	add("id", ({"teeth"}) );
        set_short( "ħ�ޡ�������" );
	set_long(@C_LONG
һֻȫ���⣬�Ĵ���ײ��ħ�ޡ�
C_LONG
	);
	set_perm_stat("str", 10 );
	set_perm_stat("dex", 11 );
	set_skill("dodge", 40 );
	set_skill("tactic", 70 );
	set("tactic", "melee" );
	set("killer", 1);
	set("pursuing",1);
	set("max_hp", 200);
	set("hit_points", 200);
	set("justice",1);
	set_natural_armor(45,10);
	set_natural_weapon(20,12,20);

       set("c_killer_msg","ͻȻ�������һ�����ߣ��ڳ������ת�˸����ᣬ����Ϯ����\n");
       set_c_verbs( ({"%sͻȻ��ֱ������%s","%sת�˸������%s���˹�ȥ",
              "%s�ڵ�������ǰ��ͻȻҧ��%s"}) );
       set_c_limbs( ({"����","����","ͷ��","����"}) );
       set("c_death_msg","%s˵�����ˣ�������ҵ�Ч�ң�˵��˵������һ�Ѷ���....\n");
       set("alt_corpse",IWARO"shortblade1");   
}
