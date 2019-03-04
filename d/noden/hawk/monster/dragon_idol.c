#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dragon idol", "���ο���" );
        add( "id", ({ "idol", "dragon" }) );
        set_short( "���ο���" );
        set_long(
                "�㿴��һ���޴�����ο��ܣ�������֫�ƺ���һЩ����������ǣ������\n"
        );
        set( "unit", "ֻ" );
        set( "race", "dragon" );
        set( "alignment", -1100 );
        set_natural_armor( 50, 30 );
        set_natural_weapon( 40, 30, 50 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 26 );
        set( "hit_points", 700 );
        set( "max_hp", 700 );
        set( "aim_difficulty",
                ([ "critical":30,"vascular":20,"weakest":20,"ganglion":35]) );
        set( "special_defense",([ "all":30,"none":30 ]) );
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set( "tactic_func", "my_tactic" );
        set( "wealth/gold", 100 );
        set( "killer", 1);
        set( "pursuing", 1);
        set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
        set_c_verbs( ({ "%s������%s��ҧ", "%s�þ�צץ��%s" }) );
}

int my_tactic()
{
        object *victim;

        if( random(20)<3 ) {
                tell_room( environment(this_object()),
                        "\n���ο��ܷ���һ�����µĺ�������ӿ����������ɫ������....��\n\n",
                        this_object() );
                victim = query_attackers();
                victim->receive_special_damage( "magic", 30 );
                return 1;
        }
        return 0;
}
