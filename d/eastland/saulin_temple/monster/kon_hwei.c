#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/mob_special";

void create()
{
        ::create();
        set_level(16);
        set_name( "kon hwei", "����Ժ���� �ջ�" );
        add ("id", ({ "hwei","monk","kon" }) );
        set_short( "����Ժ���� �ջ�");
        set("unit","λ");
        set_long(@DESC
����һλ������У�������ü�����Ĵ��������������е�Ц�ݣ���Ȼ
�����书\��Ϊ�Ȳ�������ͬ�������ǣ��������Ծ�ѧ�����ϵļ��⣬
ȴ�����ɴ�ʦ��ʮ�ֳ羴����Ϊ���־�ʦ��һ����������������Ժʵ
���������顣
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 25);
        set_perm_stat("dex", 25);
        set_perm_stat("int", 29);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 500);
        set("force_points", 500);
	set("force_effect",2);
        set_natural_weapon(30, 22, 34);
        set_natural_armor(65, 20);
        set("special_defense", ([ "all" : 30, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",100);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
	equip_armor(SAULIN_OBJ"cloth3");
	equip_armor(SAULIN_OBJ"necklace2");
        set("special_attack",(["damage_type" : "mental","main_damage" : 20,
				"random_dam" : 40 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","�ջ۴�ʦ�૵ĳ����������ľ�..\n"+
    "\nͻȻ������������а�������ܵ�ǿ�ҵ����� ..\n\n");
set("c_room_msg","�ջ۴�ʦ�����������ľ�������");
set("c_room_msg2", "�������а�� ...\n");
}

