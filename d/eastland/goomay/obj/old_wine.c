#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "quaff_potion", "drink" );
        add_action( "quaff_potion", "quaff" );
}

void create()
{
        set_name("old wine","�����Ͼ�");
        add( "id" , ({ "wine" }) );
        set_short("�����Ͼ�");
        set_long(
		 "����һ���Ϻõĳ����Ͼƣ������������Ƶ���⣬����ı�ǩ�����Ա�ʶ�ˡ�\n");
        set("unit","��");
        set("weight", 10);
        set("value", ({20, "silver"}) );

}

int quaff_potion(string arg)
{
        if( ! arg || !id(arg) ) return 0;
        write( 
                "�㹾ཹ�ཱུغ���һ�����Ͼƣ�������һ�����а����������һ�㡣\n");
        tell_room( environment(this_player()), 
                this_player()->query("c_name")+"��ཹ�ཱུع���һ�����Ͼƣ�Ȼ���������������\n"
		, this_player()
        );
        remove();
        return 1;
}
