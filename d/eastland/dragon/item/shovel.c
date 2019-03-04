#include "../../layuter.h"
inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Silver Shovel", "������");
	add ("id",({ "shovel" }) );
	set_short("������");
	set_long(
            "һ�������ӣ�����������(dig)��\n"
	);
	set( "weapon_class", 10 );
	set( "type", "blunt" );
	set( "min_damage", 1 );
	set( "max_damage", 2 );
	set( "weight", 20 );
	set( "value", ({ 50, "silver" }) );
	set( "unit", "��" );
}

void init()
{
        add_action("to_dig","dig");
}

int to_dig(string str)

{
        object obj1, obj2,ob3;
        
        if ( !str || str!="north" )
          write("Dig what ?\n");
        else {
          obj1=environment(this_object());
          if (obj1==this_player()) {
            obj2 = environment(obj1);
            if (((int)obj2->query("layuter_dig")==1)&&((int)obj2->query("beer_control")==1)) 
              {
               obj2->set("beer_control",0);
               write("���ڵ�һƿ����Ů����\n");
                  ob3=new(Lditem"beer");
                  ob3->move(obj2);
              }
            else
              write("�����������˺ܾã������ڲ����κζ�����\n");
          }
          else return notify_fail("�����ϲ�û�й��ߡ�\n");  
        }
        return 1;
}
