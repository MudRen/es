#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create(){

        set_name("ching","��Ҷ��");
        add( "id" , ({ "wine","chinese wine","ching" }) );
	set_short( "��Ҷ��" );
      set_long("����Զ���������Ҷ�ࡣ\n");
        set("unit","��");
	set("ident", "CHING");
        set("weight", 10);
        set("value",({20, "silver"}) );
}

int quaff_potion(string arg)
{

        if( ! id(arg) ) return 0;
        write(
                "�����һ����Ҷ�ࡣ�е�ͷ�е����εģ�������һ���˷ܵĸо���\n"
        );
        tell_room( environment(this_player()) ,
                this_player()->query("c_name")+"����һ����Ҷ�࣬�Եúܿ��ĵ�����
��\n",
                this_player() );

        remove();
        return 1;

}

