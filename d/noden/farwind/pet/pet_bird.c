
inherit "/std/pet.c" ; 

void init()
{
	::init();
    add_action( "order_me","order_bird");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet bird","������");
        add( "id", ({ "bird","pet" }) );
        set_short( "��·�ľ�����");
        set_long(
@C_LONG
��ֻ����ĳ�˵ĳ����ϲ���������˷�����ȥ����������
����ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹ�С���벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_bird <commands> ����������
C_LONG
        );
        set_perm_stat("str", 1);
        set_perm_stat("con", 1);
        set_perm_stat("dex", 4);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 50);
        set("weight", 30);
        set("post_name","'s pet bird");
        set("c_post_name","�ľ�����");
        set("prevent_give_money", 1);
        set("pet_type", "bird");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s������%s��ȥ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "�������౵Ľ���������ļ��������ȥ��\n",
        "���������ĳ���ڵ����Ҷ����ԡ�\n"
        }));
        setenv("C_MMIN","$N�����������˷��˹�����");
        setenv("C_MMOUT","$N�����������˷ɿ���");
}
