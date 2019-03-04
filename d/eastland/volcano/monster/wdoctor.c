#include <../oldcat.h>
inherit MONSTER ;

int be_get;
void create()
{
        object ob1;

	::create();
	set_level(16);
        set_name( "Old shaman", "����ҽ" );
        set_short( "����ҽ" );
	add( "id", ({ "shaman" }) );
	set_long(
@LONG
�㿴��һ����ͺܴ������ҽ�������������ƣ����ֵģ�������������������������
�����ܺ��ȵ�����ҽ���������õ����ģ����������ǲ��ǳ�̫���ǹ��ˣ�����������
������Ա���������������ҩ��
LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
        set_perm_stat("str",25);
        set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 80 );
        set_skill( "anatomlogy", 80 );
        set("defense_type","dodge");
        set( "aim_difficulty", ([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "max_hp", 750 );
        set( "hit_points", 750 );
        set_natural_armor( 58, 16 );
        set( "natural_weapon_class1", 3 );
        set( "natural_min_damage1", 1 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", -500 );
        set( "wealth/gold", 50 );
        set( "inquiry", ([ 
             "candy":"@@ask_candy",
             "box":"@@ask_box",
             "heal":"@@ask_heal",
             "potion":"@@ask_heal",
             "pill":"@@ask_heal",
             ]) );
        ob1=new(OWEAPON"dagger02");
        ob1->move(this_object());
        wield_weapon(ob1);
        equip_armor(OARMOR"amulet1");
        equip_armor(OARMOR"boots2");
        equip_armor(OARMOR"cloak1");

}

void ask_candy(object who)
{
   if (be_get) {
     tell_object(who,
       "\n����ҽ˵���㳤�ĺܱ�Ǹ��� ! ���������ǹ��ѱ����˽����ȵ��ˡ�\n");
     return;
   }
   tell_object(who,
     "\n����ҽ˵������Ҫ����ص��ǹ����͵���ʮ���ҽ�����\n");
   return;
}

void ask_box(object who)
{
  tell_object(who,
    "\n����ҽ˵���Ǹ��ں����п����Ǳ�����˪͵���ˣ��Ҳ�֪�������ǣ�����û��\n"
      "��Ҫ���ǲ�Ҫ�����ȽϺã��������ľ����Ĵ������������޿��ͺΡ�\n\n");
  return ;
}

void ask_heal(object who)
{
  tell_object(who,
   "����ҽ˵������������һ������ҩ�裬���ͻ�ȱһ��ҩ��(�˲ι�)������������\n�����ң��Ҿͷ���һ�š�\n");
  return;
}

void init()
{
    add_action( "do_pay", "pay");
}

int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="manlike fruit"))
     return 0;
   if (!item->query(me->query("name"))) {
     printf("����ҽ˵������ȥ����͵���˲ι���͵��֮����������ȡ��\n");
     item->move(me);
     return 1;
   }
   write("����ҽ˵��������������Ҫ���˲ι���лл��\n\n");
   write("���������ҽ���˲ι������������ͷ��ֻ����˻��һ����һ��ŨŨ����ɫ������ǹ���\n��Ʈ�˳�����������������֮�У�����֮�У�����Լ��������ҽ��֪���ڹ��ӱ���ʲ�ᣬ��\n����ɢȥ����ע�⵽�Ǵ��������û���κζ����ˡ�\n\n");
   write("����ҽ˵�������Ҹ���ɵ�����ҩ�裬һ�ŷ���ɡ�\n");
   item->remove();
   ob=new(OOBJ"wpill");
   ob->set(this_player()->query("name"),1);
   ob->move(this_player());
   return 1;
}

int do_pay(string arg)
{
        string who, type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "\n��˭������Ǯ��\n" );
        if( !id(who ) ) return 0;

        if (be_get) {
           tell_object(this_player(),
              "\n����ҽ˵�����ǹ���������ȥ�ˣ�����Ǯ�������߲��ܡ�\n");
           return 1;
        }

        if( type != "gold" ) {
         tell_room( environment(), ({
             "\n����ҽ˵��: �ܱ�Ǹ��ֻ�н�Ҳ��ܴ��ҵ��ġ�\n" }),
          this_object() );
          return 1;
	}

       if( !this_player()->debit(type, num) ) 
           return notify_fail( 
           "\n��û��������ҡ�\n" );

       if(num<10) {
         tell_room( environment(),
          "\n����ҽ˵��: Ǯ���������ٸ���һ��ɣ���ξ�������������ˡ�\n" ,
          this_object() );
                return 1;
	}

        if (num>=10) {
          tell_object(this_player(), 
             "\n����ҽ˵��: �� ! �Ҿ���ʹ������ɿ�������ɡ�\n");
        ob1=new(OOBJ"y_chocolate");
        ob1->move(this_player());
        be_get=1;
	return 1;
	}

}

void reset()
{
  be_get=0;
}
