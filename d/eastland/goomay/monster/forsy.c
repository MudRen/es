
#include "../goomay.h"

inherit MONSTER;

void create()
{
        object ob1,ob2;
        ::create();
        set_level(11);
        set_name( "forsy the mine worker", "��С��" );
        add ("id", ({"forsy","worker"}) );
        set_short( "��С��" );
        set_long(
        "����һ������ʮ��ǿ׳�������ˣ���һ�۾Ϳ��Կ�����������\n"
        "�����ĵܵ�С�ģ���Ϊ���Ǹ�������˫��̥��\n");
		set("alignment",400);
		set( "gender", "male" );
		set( "race", "orc" );
		set( "unit", "��" );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "str", 18 );
        set_perm_stat( "int", 17 );
        set_perm_stat( "con", 20 );
        set_perm_stat( "piety", 15);
        set_perm_stat( "karma", 17);
        set_skill("thrusting",70);
        set_skill("parry",70);
        set ("max_hp", 470);
        set ("hit_points", 470);
        set ("wealth", ([ "gold": 10 ]) );
        set_natural_weapon(19,10,25);
        set_natural_armor(35,15);
		set ("weight", 400);
		wield_weapon(Obj"iron_pick");
        equip_armor(Obj"head_cap");

        set( "inquiry", ([
                "����" : "@@ask_hunter",
                "���˰���" : "@@ask_hunter",
		"hunter" : "@@ask_hunter"]));

}

int ask_hunter()
{
	object ob1;
   if( (int)this_player()->query_quest_level("Goddess_statue") != 1 ){
       tell_object(this_player(),"С�Ŀ����������ɶ������ʶ�Ҹ���𣿡�\n" );
                return 1;
	}

tell_object(this_player(),
@C_WU
С������һ�������ѹ����⼸������������ûؼҿ����ˣ���������
��Ҫ�Ķ���Ҫ�����ҵ��ϰ�������������ȥ�������𣿡�

������ش�С��Ӳ������һ�žɾɵ���Ƥ��Ȼ���Ҳ�Ƶ��ܻؼ�ȥ�ˡ�
C_WU
);
	ob1 = new( Obj"paper1" );
        ob1->move(this_object());
        this_player()->set_temp("get_paper",1);
        environment(this_player())->delete("forsy_appear");
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
		remove();
        return 1;
}

