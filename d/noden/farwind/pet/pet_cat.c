
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_cat");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet cat","����è");
        add( "id", ({ "cat","pet" }) );
        set_short( "��;������è");
        set_long(
@C_LONG
��ֻè��ĳ�˵ĳ����ϲ����������������ȥ���������������Ƕ�������
���۾�����ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹ�è�䣬�벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_cat <commands> ����������
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set_temp("effect/power-boost", 1);
        set("max_load", 75);
        set("weight", 100);
	set("post_name","'s pet cat");
        set("c_post_name","������è");
        set("prevent_give_money", 1);
        set("pet_type", "cat");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "è���������˼���������Ľű߰���������������ȥ��\n",
        "è�买���˱���������������ʼ��צ��ϴ����\n"
        }));
        setenv("C_MMIN","$N����������Ĳ������˹�����");
        setenv("C_MMOUT","$N����������Ĳ����߿���");
}
