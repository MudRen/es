#include "mudlib.h"
#include "/include/move.h"

#define MAX_AC ({ 8,35,4,4,8,8,8,8,8,8 })
#define MAX_DB ({ 3,6,4,4,3,3,6,6,3,3 })
#define TYPES ({"head","body","arms","hands","legs","feet","shield","cloak","saddle","tail"})
#define UNITS ({"��","��","��","˫","��","˫","��","��","��","��" })
#define ADD_NAME1 ({"Ƥñ","Ƥ��","Ƥ�ۻ�","Ƥ����","Ƥ��","Ƥѥ","Ƥ��","Ƥ����","Ƥ��","��β"})
#define ADD_NAME2 ({"Ƥͷ��","Ƥ����","Ƥ����","Ƥ����","Ƥȹ","ƤЬ","Ƥ��","Ƥ����","Ƥ����","Ƥβ��"})
#define WEIGHT ({50,150,50,40,80,70,130,100,110,50 })
#define EXTRA_ID1 ({"hat","armor","armband","gloves","pants","boots","shield","cloak","saddle","tail"})
#define EXTRA_ID2 ({"hood","cloth","sleeves","bracers","skirts","shoes","shield","hide","seat","tail armor"})       
inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "woman", "Ů�÷�ʦ" );
        set_short("Ů�÷�ʦ");
        set("unit","λ");
        set_long(
@C_LONG
һλ�������๤����Ů�÷죬������Ҫ�����ǰ�ëƤ���Ƴɸ��ַ���
C_LONG
);
        set ("gender", "female");
        set ("race", "human");
	set("no_attack",1);
}
void init()
{
        add_action( "kill_me", "kill");
        add_action( "do_choose", "choose");
}

int kill_me(string arg)
{
  if (arg=="woman")
	{
	tell_object(this_player(),
		"Ů�÷�ʦ�����ص� �� �����ã�û������æ�� ?? ��ȥ��ȥ !!��\n"
		"˵���Ͱ����Ƴ����⡣\n" 
		);
      this_player()->move_player( "/d/adventurer/hall/adv_libra1", "SNEAK" );
        tell_room( "/d/adventurer/hall/adv_libra1", 
         this_player()->query("c_name") + "���˺��˳�����\n"
        ,this_player() );
        return 1;
	}
	else 
	this_player()->command("kill "+arg);

}
int do_choose(string arg)
{
 int i,AC,DB,num,skin_level,make_skill;
 object armor,item;
 string c_skin_name;
 
 item = present("skin",this_object());
 if (!(int)this_player()->query_temp("give_skin" )) {                                                                      
        
        tell_object(this_player(),
        "Ů�÷�ʦ˵��: ���Ȱ����Ƥ����....\n"); 
 return 1;
 }
 for( i=0; i<sizeof(allocate(10)); i++ ) {
     if (arg != TYPES[i] ) continue;
     if (arg = TYPES[i] ) {
     skin_level= query("skin_level");
     make_skill= query("make_skill");
     c_skin_name = query("c_skin_name");
     if (skin_level < 5) skin_level=5;
     AC = 1 + MAX_AC[i]*(skin_level-random(3))*make_skill/1050;
     DB = MAX_DB[i]*(skin_level-random(3))*make_skill/1000;
     num = AC*2+DB*5;
     if (this_player()->query("wealth/gold")<num+1) {
     tell_object(this_player(),
     "Ů�÷�ʦ˵��: ร��Բ�������ֽ𲻹��??\n"
          );
     command("give skin to " +(string)this_player()->query("name"));
     this_player()->delete_temp("give_skin");
     return 1;
     }
     this_player()->add("wealth/gold",-num);
     armor = new("/d/adventurer/hall/obj/armor");
     armor->set("type",TYPES[i]);
     armor->set("armor_class",AC);
     armor->set("material","adventurer");
     armor->set("defense_bonus",DB);
     armor->set("unit",UNITS[i]);
     armor->set("weight",WEIGHT[i]);
     armor->set("value",({ num, "gold" }) );
     armor->set("c_skin_name",c_skin_name);
     if (random(10) > 5) {
     armor->set("add_name", ADD_NAME1[i]);
     armor->add( "id", ({ EXTRA_ID1[i] }) );
     armor->set_name(EXTRA_ID1[i]);
     }
     else { 
     armor->set("add_name", ADD_NAME2[i]);
     armor->add( "id", ({ EXTRA_ID2[i] }) );
     armor->set_name(EXTRA_ID2[i]);
     }
     armor->set_short(c_skin_name + (string)armor->query("add_name"));
     tell_room(environment(this_player()),
             "Ů�÷�ʦ��ʼ��Ƥ�������С�飬Ȼ��ܿ�ķ��������\n");
     command("say �������Ҫ�ķ��ߣ���ӭ���٣��´�������");
     if( (int)(armor->move(this_player())) != MOVE_OK )
     armor->move(environment(this_object()));
     this_player()->delete_temp("give_skin");
     item->remove();
     return 1;
        }
        }
     tell_object(this_player(),
@MISS
Ů�÷�ʦ˵��: ร��Բ�����û������Ҫ�����ַ����??
MISS
     );
     return 1;
}
int accept_item(object me,object item)
{
	string name,c_skin_name;
	int skin_level,make_skill;
	name=(string)item->query("name");
        if ( !name || ( name!="skin" )) return 1;
        if ((string)this_player()->query("class") != "adventurer" ) {
        tell_object(me,
@MISSION
Ů�÷�ʦ˵��: �Բ�����ֻ����ð����...        
MISSION
                );
        item->remove();
        return 1;
        }
        tell_object(me,
@MISSION
Ů�÷�ʦ˵��: ร���ã�����Ҫ����Щʲ�������??
�������������ķ��������漸��:
head(ͷ��)��body(����)��arms(�ֱ�)��hands(�ֲ�)��legs(�Ȳ�)
feet(�Ų�)��shield(����)��cloak(����)��saddle(��)��tail(β��)
�����ѡ��(choose)���е��κ�һ�֡�
MISSION
	);
		this_player()->set_temp("give_skin",1);
                c_skin_name=(string)item->query("c_skin_name");
                skin_level= item->query("skin_level");
                make_skill= item->query("make_skill");
                set("make_skill",make_skill);
                set("skin_level",skin_level);
                set("c_skin_name",c_skin_name);
//                item->remove();
        return 1;
}
          
