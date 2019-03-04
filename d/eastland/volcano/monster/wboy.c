#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(5);
	set_name( "The boy", "������С�к�" );
	add( "id", ({ "boy" }) );
	set_short( "������С�к�" );
	set_long(
          "һ���������С�к���������������͡�\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 0 );
	set_perm_stat( "str", 8 );
	set( "wealth/gold", 5 );
        set( "hit_points", 100);
        set( "max_hp", 100);
        set("natural_armor_class",12);
        set("natural_defense_bonus",5);
        set("chat_chance",15);
        set("chat_output",({
        "С�к�˵�����ĵ����尢���Ǹ����ǳ԰ɡ�\n" }) );

        ob1=new(OWEAPON"wgun");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );

        equip_armor(OARMOR"dudo2");
}

int accept_item(object me,object item)
{
   string name;
   int candy;
   
   name=(string)item->query("name");
   item->remove();
   if (this_player()->query_temp("ohio")>=2) {
     tell_object(me,
        "\n������һ�����ܣ���һ�죬�����������ʱ��������һ����Ҫ�����ˡ�\n"
        "�Һܺ��¾ͼ���ææ���ܻ����ˡ�\n");
     return 1; }

   switch(name) {
   case "gold_chocolate" :
         if (this_player()->query_temp("gold_chocolate"))
            tell_object(me,
              "С�к�˵�������ǹ����Ѿ��Թ��ˣ���û�б��?\n");
         else {
            this_player()->set_temp("gold_chocolate",1);
            tell_object(me,
              "С�к�˵���úóԣ�лл��\n"); }
         break;
   case "silver_chocolate" :
         if (this_player()->query_temp("silver_chocolate"))
            tell_object(me,
              "С�к�˵�������ǹ����Ѿ��Թ��ˣ���û�б��?\n");
         else {
            this_player()->set_temp("silver_chocolate",1);
            tell_object(me,
              "С�к�˵���úóԣ�лл��\n"); }
         break;
   case "red_chocolate" :
         if (this_player()->query_temp("red_chocolate"))
            tell_object(me,
              "С�к�˵�������ǹ����Ѿ��Թ��ˣ���û�б��?\n");
         else {
            this_player()->set_temp("red_chocolate",1);
            tell_object(me,
              "С�к�˵���úóԣ�лл��\n"); }
         break;
   case "blue_chocolate" :
         if (this_player()->query_temp("blue_chocolate"))
            tell_object(me,
              "С�к�˵�������ǹ����Ѿ��Թ��ˣ���û�б��?\n");
         else {
            this_player()->set_temp("blue_chocolate",1);
            tell_object(me,
              "С�к�˵���úóԣ�лл��\n"); }
         break;
   case "yellow_chocolate" :
         if (this_player()->query_temp("yellow_chocolate"))
            tell_object(me,
              "С�к�˵�������ǹ����Ѿ��Թ��ˣ���û�б��?\n");
         else {
            this_player()->set_temp("yellow_chocolate",1);
            tell_object(me,
              "С�к�˵���úóԣ�лл��\n"); }
         break;
   default :
             return 1;
   };

   candy=0;
   if (this_player()->query_temp("gold_chocolate"))
     candy+=1;
   if (this_player()->query_temp("silver_chocolate"))
     candy+=1;
   if (this_player()->query_temp("red_chocolate"))
     candy+=1;
   if (this_player()->query_temp("blue_chocolate"))
     candy+=1;
   if (this_player()->query_temp("yellow_chocolate"))
     candy+=1;

   if (candy==5 && this_player()->query_temp("ohio")) {
      this_player()->set_temp("ohio",2);
      tell_object(me,
          "\n������һ�����ܣ���һ�죬�����������ʱ�ᣬ����һ����Ҫ�����ˡ�\n"
          "�Һܺ��¾ͼ���ææ���ܻ����ˡ�\n"); }
   return 1;

}
