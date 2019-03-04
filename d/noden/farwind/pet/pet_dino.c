#include "pets.h"

inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_dino");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(2);
        set_name("pet dino","С����");
        add( "id", ({ "dino","pet" }) );
        set_short( "û�˹ܵ�С����");
        set_long(
@C_LONG
��ֻС������ĳ�˵ĳ����ϲ����������������ȥ���������������Ƕ�
�ɰ�����ɫ�۾�����ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹԿ������벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_dino <commands> ����������
C_LONG
        );
        set_perm_stat("str", 7);
        set_perm_stat("con", 5);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 200);
        set("weight", 900);
        set_temp("effect/power-boost", 1);
        set("post_name","'s pet dino");
        set("c_post_name","��С����");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "С��������һ����Ƿ�����һ������ɫ���̡�\n",
        "С�������������˵������Ҫ������β�͡���\n"
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
