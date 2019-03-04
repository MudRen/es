#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The young man", "����������" );
	add( "id", ({ "man" }) );
	set_short( "����������" );
	set_long(
         "һ������������꣬�����Դ��԰׵����ף�����������΢���ͷ����\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 0 );
	set_perm_stat( "str", 16 );
        set_perm_stat( "dex", 16 );
	set( "wealth/gold", 2 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",45);
        set("natural_defense_bonus",15);
        set_natural_weapon(18,9,15);
        set("chat_chance",15);
        set("chat_output",({
            "�����������������������ү�����ң���Ȼ����û��ָ���ˡ�\n"
            }) );
        set( "inquiry", ([
             "trouble" : "@@ask_trouble",
             "help" : "@@ask_trouble",
             "rose" : "@@ask_rose",
             ]) );
}

void ask_trouble(object who)
{
  tell_object(who,
     "\n����˵���Ұ����˲�������������λŮ���ӣ����ǣ�����������\n"+
     "�� ! ��λ��ɽ���˾�Ȼ˵�������Ҵ�����ɫ��õ�廨������飬���ʹ�Ӧ��\n"+
       "��˭��֪������������ɫ��õ�廨�����Ͳ����ڡ�\n\n");
}

void ask_rose(object who)
{
  tell_object(who,
     "\n����˵������Ҫһ����������ɫõ�廨����������һ����Һ���\n\n"
  );
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
  if (!name || name!="blue rose") {
    return 0;
  }

  if (this_player()->query_temp("blue_rose")) {
    write("����˵���ǳ�лл�㣬������춿���Ȣ��һλ�����\n");
    write("        ���Ѿ�������Ҫ���õ���ˡ�\n");
    item->move(me);
    return 1;
  }
  
  if (item->query(me->query("name"))) {
    write("����˵���� ! �����������õ�壬�ǳ�лл�㣬����������ˡ�\n");
    write("�����ٸ�����һ�����ܣ����������Ҹ���˵�����Ǵ�������и����\n");
    write("�㳡�����ܣ����Ҳ�̫�ǵ��ˣ����������ȥ���Ҹ��׹�춹㳡(square)���¡�\n");
    me->set_temp("blue_rose",1);
    item->remove();
    return 1;
  }
  
  write("�������������õ��һ�ۣ�������������İɡ�\n");
  write("����Ҫ����������õ�壬лл��\n");
  item->move(me);
  return 1;

}
