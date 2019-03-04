#include <../takeda.h>

inherit SELLER;
inherit MONSTER;

#include "../takeda.h"

void create ()
{

        ::create();
        set_level(17);
        set_name( "Zhan Hsin", "����" );
        add ("id", ({ "zhan", "hsin" }) );
        set_short( "����");
        set( "race" , "elf" );
        set("unit","λ");
        set("alignment",100);
        set("weight",400);
        set("wealth/silver",500);
        set_long(
           "�����ˣ���Ų�԰�ӣ����ȭ�����ֽŻ�㣬ԭ�ڹ������ֲˣ���Ϊ\n"
           "��ɽ���Ƶ������Ϣ��������ͷ�졣\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("str",25);
        set_perm_stat("kar",30);
        set( "chat_chance",8);  
        set("chat_output",({"����Ц��: �˿�Ҫ��Ҫ�Ե㶫��??\n"}));
        set("max_hp",500);
        set("hit_points",500);
        set("natural_defense_bonus",30);
        set ("natural_weapon_class1", 10);
        set ("natural_armor_class", 50);
        set ("special_defense",(["fire":2,"cold":-2,"magic":2]));
        set ("gender", "male");
        set_skill("longblade",80);
        set_skill("parry",80);
        set("tactic_func","my_tactic");
//        set( "shop_name", "vendor" );
        set_inventory( ({
                       ({ TOBJ"cow.c",10,10}),
                       ({ "/d/noden/farwind/items/ching.c",10,10}),
                       ({ TOBJ"dofu.c",10,10}),
                       ({ TOBJ"dumpling.c",10,10}),
                       ({ TOBJ"vegetable.c",10,10}),
                       }) );


        set( "inquiry", ([
             "menu" : "@@show_menu"
                                ]) );
        wield_weapon(TWEAPON"yanlin");
        equip_armor(TARMOR"black_cloth");
}               

int my_tactic()
{
   mixed *attackers;
//   object who,victim,env;
   int loop;
//   env =environment(this_object());
//   who =present(this_object(),env);
   if (random(20)<15) return 0;
   if (!query_attacker()) return 0;       
	tell_room(environment(this_object()),
	    "\n����ӻ����ͳ��������ӣ�˵��: �͹�����......."
	    "\n����˹�ȥ���ĵسԽ���������ȫ������ս������......\n");
	this_object()->receive_healing(10);
//	add("hit_points",10);
   	attackers=all_inventory(environment(this_object()));
   	for (loop =0; loop<sizeof(attackers);loop++)
   		attackers[loop]->cease_all_attacks();
//   	attackers[loop]->remove_attacker();
	return 1;
/*
   attackers=who->query_attackers(this_object());
   for (loop =0; loop<sizeof(attackers);loop++)
   attackers[loop]->remove_attacker();
   attackers[loop]->cease_all_attacks();
   who->cease_all_attacks();
   return 0;
*/
}
void init()
{
	npc::init();
	seller::init();
}