#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(6);
        set_name("Teeder","Ů��˾�ٵ�" );
        add ("id", ({"drow", "teeder" }) );
        set_short( "Teeder","Ů��˾�ٵ�" );
        set("unit","λ");
        set_long(
@C_LONG
��λ��������������Ů�Ӻ����ܵ����൱�̶ȵľ��ţ����������ֶ�
�ؾ������������㻹���������
C_LONG
        );
        set_perm_stat("str", 6);
        set_perm_stat("int", 16);
        set_perm_stat("kar", 12);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 9);
        set("natural_max_damage1",13);
        set ("natural_armor_class", 15);
         set("inquiry",([
             "help" : ({
             "�������ܲ������ҳԿ������� \n"})
               ]));
        set("chat_chance",15);
        set("chat_output",({
            "�ٵ�˵�����ö����ܲ��ܰ��(help)�ң����� \n",
            "�ٵ����������۾�����ͣ����������� \n"}));
    set( "special_defense", ([
        "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "female");
        set("wealth/copper",3000);
   set("weight" , 300 );
        set ("race", "drow");
        equip_armor(ARM"feet");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="chicken"))
     return 1;
write("\n�㿴���ٵ������¾Ͱѿ����Ե��ˣ���������ģ���ò�����\n");
write("\n�ٵ�˵����лл�㡫�������뿪���ǰ���и��ֲܿ��Ĺ��\n");
write("\n��ȵ�ม����ø���������ม���\n");
write("\n....\n");
write("\n...\n");
write("\n...\n");
write("\n..\n");
write("\n..\n");
write("\n\n");
   item->remove();
   if (!this_object()->query("wine")) {
     write("�ٵ�˵������ƿ�����Ǵ峤���ҵģ������ڸ��㣬ϣ���������á�\n");
     ob=new(OBJ"wine");
     ob->move(this_player());
     set("wine",2);
   }
   else
  write("\n�ٵ�˵����ŷ���������������ҵ������ˡ����ܸ����ˡ���\n");
   return 1;
}
