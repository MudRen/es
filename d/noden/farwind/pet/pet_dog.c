
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_dog");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet dog","�󱿹�");
        add( "id", ({ "dog","pet" }) );
        set_short( "����Ĵ󱿹�");
        set_long(
@C_LONG
��ֻ����ĳ�˵ĳ����ϲ����������������ȥ���������������Ƕ���͵�
�۾�����ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹԹ������벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_dog <commands> ����������
C_LONG
        );
        set_perm_stat("str", 3);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 100);
        set("weight", 250);
        set("post_name","'s pet dog");
        set("c_post_name","�Ĵ󱿹�");
        set("prevent_give_money", 1);
        set("pet_type", "dog");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "����ҡ������β�ͣ���Ҫ�����档\n",
        "����ſ�������ϣ��������������ˮ��\n"
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
