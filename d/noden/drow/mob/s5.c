#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name("cobra", "����ٻ" );
        set_short("����ٻ" );
        set_long(
@C_LONG
�ų������ķ���ٻ�������۾��ߣ������������������
������������ǳ����֪����Ҳ���ף���ȥ����������ȷ
��ѡ��
C_LONG
        );
        set( "unit", "��" );
        set( "alignment", -730 );
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 14 );
        set( "natural_max_damage1", 18 );
        set( "tactic_func", "emit_poison" );
        set( "chat_chance",15);
//        set( "chat_output", ({
//                                         });
        set_c_limbs( ({ "ͷ��", "����", "β��" }) );
        set_c_verbs( ({ "%s��ͷ���죬��%sҧȥ" }) );
}
int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "����ٻ���𾱲��Ĵ��ۣ��ݺ�����ҧ�£������һ���ʹ ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 6 );
        return 1;
}       
