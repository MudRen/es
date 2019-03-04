
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_pig");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet pig","������");
        add( "id", ({ "pig","pet" }) );
        set_short( "�����Ҷ����Ե�������");
        set_long(
@C_LONG
��ֻ��������ĳ�˵ĳ����ϲ����������������ȥ���������������Ƕ�
��ڵ������ۺ���ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹ�С���벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_pig <commands> ����������
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 3);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 2);
        set("max_load", 75);
        set("weight", 200);
        set("post_name","'s pet pig");
        set("c_post_name","��������");
        set("prevent_give_money", 1);
        set("pet_type", "pig");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s������%sһҧ", "%s������ͷ��%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "�����������ı��ӵ���������ȥ��\n",
        "������ҡ�����Ķ�β�ͣ�������ת��תȥ��\n"
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
