
inherit "/std/pet.c" ;

void init()
{
	::init();
     add_action( "order_me","order_rat");
     add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet rat","������");
        add( "id", ({ "rat","pet" }) );
        set_short( "�ɰ���������");
        set_long(
@C_LONG
��ֻ��������ĳ�˵ĳ����ϲ����������������ȥ���������������Ƕ�
��ڵ�С�۾�����ؿ����㡣���Ĳ����Ϲ���һ�����ӣ�����д����
        ����������������������������������������������
              ���ǹ������벻Ҫ�����Ҷ���·��
        ����������������������������������������������
��������������ˣ�������� order_rat <commands> ����������
C_LONG
        );
        set_perm_stat("str", 1);
        set_perm_stat("con", 1);
        set_perm_stat("dex", 3);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 2);
        set("max_load", 50);
        set("weight", 50);
        set("post_name","'s pet rat");
        set("c_post_name","��������");
        set("prevent_give_money", 1);
        set("pet_type", "rat");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "�����������Ƕ���ڵ��۾�����Ŀ����㡣\n",
        "������������Ŀڴ����ҳ�һ���Ǭ�����˵س�������\n"
        }));
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
}
