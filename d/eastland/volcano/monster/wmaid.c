#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "The young lady", "����������Ů" );
	add( "id", ({ "lady" }) );
	set_short( "����������Ů" );
	set_long(@LONG
    һ�������������Ů��һϮ����ĳ���������Ϸ��������ĺ��Σ�ӣ��С�ڣ�
�����鶯��һ˫���������������������ᣬ�������������ƻ���һ�ɶ�����
�ϣ���ׯ�д���������
LONG
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set( "alignment", 0 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set( "wealth/gold", 1 );
        set( "hit_points", 100);
        set( "max_hp", 100);
        set( "inquiry",([
             "marry" : "@@ask_marry",
             "rose" : "@@ask_rose",
             ]) );
        set("natural_armor_class",35);
        set("natural_defense_bonus",10);
        set_natural_weapon(9,7,10);
        set("chat_chance",5);
        set("chat_output",({
            "����˵����Ҳ����Щ����Ϊ���ĺ�˧��������Ҫ�Ҽ޸��㣬�������ˡ�\n"
             }) );
        set("att_chat_output", ({
          "\n����˵����...��...���������������������ỹ�������֡�\n"
         }) );
        set("c_death_msg","%s ������һ��...���Ⱳ�ӱ����������ˡ�\n");
        set_c_verbs( ({
        "%s ����Ƶ�����ۣ�������������ʱ����%s��ȥ",
        "%s �Ӷ������廨ȭ�� %s ��ȥ",
        "%s ����ȹ�ӣ�������ɫ���еĿ�������ʱ����%s��ȥ",
        }) );
}

void ask_marry(object who)
{
  tell_object(who,
    "����˵������ֻ���Ҳ���������� ?\n"
  );
}

void ask_rose(object who)
{
  tell_object(who,
    "����˵�����������ҵ���õ�壬�Ҿͼ޸��㡣\n"
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
    write("��Ů˵���ǳ�лл�㣬���Ҽ޸�һλӢ���������ɡ�\n");
    write("        лл��������һ����ɫõ�廨��ʵ�ڲ�����˼��\n");
    write("        �����ɣ��ҳ���ʮ��������������õ�廨�����Ƕ���Ĳ�����\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  if (item->query(me->query("name"))) {
    write("��Ů˵���� ! �����������õ�壬�ǳ�лл�㣬������������������\n");
    write("        ��ʵ�ڲ�����ϲ�������ͣ��ܱ�Ǹ����Ե�ǲ�����ǿ�ģ�����\n");
    write("        �����ɣ��ҳ���ʮ��������������õ�廨�����Ƕ���Ĳ�����\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  write("��Ů�����������õ��һ�ۣ�������������İɡ�\n");
  write("����Ҫ����������õ�壬лл��\n");
  item->move(me);
  return 1;

}
