
inherit "/std/pet.c";
#include <mudlib.h>

void init()
{
        ::init();
     add_action( "order_me","order_god");
     add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(19);
        set_name( "god", "����˹" );
        set_short( "��֮ħ�� ����˹");
        set_long(
@C_LONG
"�����ǲ�ʿ���ػ���,����Ϊѧ��ħ�����߻���ħ��\n"
"��������񼫵�ħ�񣬿ɻ��ǲ������ǲ�ʿ�Ĵ����¡�\n"
"�����ڲ�ʿ��pkʱ�ͻ���֡�laugh.\n",
C_LONG
        );
        set_perm_stat("str", 60);
        set_perm_stat("con", 60);
        set_perm_stat("dex", 60);
        set_skill( "defend", 100 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set_skill( "block", 100 );
        set_skill( "longblade", 100 );
        set( "alignment", -100000 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_weapon( 60, 60, 60 );
        set_natural_armor( 90, 60 );

        set( "hit_points", 200000 );
        set( "max_hp", 200000 );

        set("max_load", 180);
        set("weight", 180);
        set("post_name","'s guard god");
        set("c_post_name","�ػ���");
        set("prevent_give_money", 1);
        set("pet_type", "god");
                set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s����һ�ѽ�%sһ��", "%s�������ϵĻ�����%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "����˹����а��������˿���Χ���ˡ�\n",

        "����˹������װѲ�ʿ�ս���\n"
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
