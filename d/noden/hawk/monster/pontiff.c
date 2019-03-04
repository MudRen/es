#include <mudlib.h>
int mistake = 0;
inherit MONSTER;

void create()
{
        object ob1, ob2, ob3, ob4;

        ::create();
        set_level(16);
        set_name("Juraken", "������");
        add( "id", ({"pontiff"}) );
        set_short("�������̴��˾ ������");
        set_long(@CLONG
����������������˳��úܸߣ�һ��������ɫ���������ϴӱ��ӵ�������һ
���ܿ��µ��˺ۡ����������Ŀ��������ʱ��һ��Ī���ĺ���ʹ�������
�˽⵽: ��һ��Ǹ����򵥵����
CLONG
        );
        set( "gender", "male" );
        set( "race", "human" );
        set( "alignment", -1500 );
        set( "natural_armor_class", 30 );
        set( "natural_defense_bonus", 20 );
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 10 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 30 );
        set_skill( "blunt", 100 );
        set_skill( "dodge", 90 );

	ob1 = new( "/d/noden/hawk/weapon/crimson_scepter" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

	ob2 = new( "/d/noden/hawk/armor/crimson_robe" );
        ob2->move( this_object() );
        equip_armor( ob2 );

	ob3 = new( "/d/noden/hawk/armor/crimson_amulet" );
        ob3->move( this_object() );
        equip_armor( ob3 );

	ob4 = new( "/d/noden/hawk/armor/crimson_ring" );
        ob4->move( this_object() );
        equip_armor( ob4 );

        set( "inquiry",([
                "potion" : "@@ask_potion",
                        ]) );
}

int ask_potion()
{
        if (this_player()->query_temp("smore_box") == 2 )
        {
                tell_object( this_player(),@LONG
���������������ϵ�ҩˮ������һ����һ��ף�������˵�ͳ��˹�����
LONG
                );
        command("kill "+this_player()->query("name") );
        mistake = 1;
        }
        else
        {
                tell_object(this_player(),@LONG
������˵��ɶ����˵ɶ��Ȼ���ת��ͷȥ�������ˡ�
LONG
                );

                return 1;
        }
        return 1;

}

void die()
{
        object killer;
        if (mistake)
        {
                tell_room(environment(this_object()),@LONG
������̾�˿�����˵����
�벻���ҵļƻ�(plan)����ʧ���ˣ����˰��ˡ�

Ȼ��Ϳ�����Ѫ�����ڵ���һ��Ҳ�����ˡ�
LONG
                ,this_object() );
                killer = query("last_attacker");
                if ( killer->query_temp("smore_box") == 2)
                        killer->set_temp("smore_box",3) ;
        }
        ::die(1);
}


