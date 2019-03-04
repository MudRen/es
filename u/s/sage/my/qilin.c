#include "pets.h"

inherit "/u/s/sage/test/pet.c" ;

void init()
{
        ::init();
    add_action("order_me","order_qilin");
    add_action("help_order", "help");
}

void create()
{
        ::create();
     set_level(19);
     set_name("qilin","������");
        add( "id", ({ "dino","pet" }) );
      set_short( "������");
        set_long(
@C_LONG
    ���ֶ����˵����500000��ǰ�Ѿ����ֵ�ʷǰ������ܹ���������
���޵������͸����ܳ�Ϊ�������˵��ˣ�������һ���ǳ������¸ҵ��ˣ�
�������ػ�����һ����
��������������ˣ�������� order_qilin <commands> ����������
C_LONG
        );
      set_perm_stat("str", 30);
     set_perm_stat("con", 30);
     set_perm_stat("dex", 30);
     set_perm_stat("int", 30);
     set_perm_stat("pie", 30);
     set_perm_stat("kar", 30);
     set("max_load", 200000);
        set("weight", 900);
        set( "hit_points", 200000 );
        set( "max_hp", 200000 );
        set_skill( "defend", 100 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
     set_temp("effect/power-boost", 100);
     set("post_name","'s qilin");
     set("c_post_name","�Ļ�����");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
     "������������������һ���ź�ɫ�Ļ�\n",
     "���������������˵����������ޡ���\n",
     "�����������˵��ʥ�˺�Ӣ���ޡ�\n",
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
