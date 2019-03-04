#include "../saulin_temple.h"

#include <stats.h>

inherit "/d/eastland/saulin_temple/monster/mob_special";
//inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "The shadow of Damo", "��Ħ�����Ӱ��" );
	add( "id", ({ "shadow", "damo" }) );
	set_short( "��Ħ�����Ӱ��" );
	set_long(@C_LONG
�㿴��һ���� .... �! ��! Ӧ��˵��һ��Ӱ�ӱȽ�ǡ������Ȼ������������
���ʵģ�������Խ����Խ���Ħ���棬�����������������������ȥ���Ե�ʮ
�ָ��ˣ�����\����֪��һЩ���ܡ�
C_LONG
	);
	set_perm_stat("dex", 25);
	set_perm_stat("str",25);
	set_perm_stat("kar",25);
	set_perm_stat("int",30);
	set_perm_stat("pie",20);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set("max_hp", 690);
	set("hit_points", 690);
	set("force_points", 2000);
	set("max_fp", 2000);
	set("alignment",-1000);
	set_natural_weapon(28, 18, 32);
	set_natural_armor(70, 38);
	set("special_defense", ([ "all" : 40, "none" : 25 ]) );
	set("aim_difficulty", ([ "critical" : 50, ]) );
	set("unbleeding", 1);
	set("c_death_msg",
@MSG

 Ӱ�ӡ�쬡���һ���ӻ�ʯ��..... ����ѽ !! ���ֱ���ס��!! ������ !!��

 Ӱ���ֿ�ʼ�������ȡ���Ȼ�����ǲ������ϵ��� !!

 ���ȸ���˵��Ħ������ !!��

 Ӱ�ӿ��İ���������˵:
 ����Ħ��������(relic)�������֣���ֻҪ�������ٻ�(call)����
   ���ͻ���� !! �����Ա����㲻���κ����ֵ���Ϯ !!�� 

 ��Ц�����Ŀ���Ӱ�ӣ���֪���ò����ٷ���������
 
MSG
);
	set( "gender", "male" );
	set("chat_chance", 5);
	set("chat_output", ({
        "Ӱ�ӳ�������˵: �������ˣ���������!\n", })
    );
	set( "inquiry", ([
		 "secret" : ({
	        "EMPTY."," ��! ������֪������Ϊʲ��Ҫ�����㣿\n"})
	]) );
        set("special_attack",(["damage_type" : "evil","main_damage" : 30,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "��Ӱ���૵ĳ���һЩ��ֵ�����..\n"+
    "\nͻȻ��һ��а�������������������ը���� ..\n\n");
//set("enemy_msg","The shadow utter a strange wrds and you feel headacke ... \n\n");
//set("room_msg","The shadow utter a strange words and curse " );
//set("room_msg2"," with its evil power.\n");
set("c_room_msg","��Ӱ�ӳ���һ��а������ģ��Ѻڰ������䴵��");
set("c_room_msg2", "������� ...\n");
}

int special_damage(object victim) 
{ 
	int dam;
	dam = 30 - (int)victim->query("alignment") / 100;
	dam = ( dam >80 ? 80 : dam );
	dam = ( dam <30  ? 30 : dam );
	return dam+random(20);
}


