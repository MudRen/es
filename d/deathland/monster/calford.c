#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "calford", "��������" );
	add ("id", ({ "calford", "dwarf", }) );
	set_short( "���˻�����������������" );
	set_long(
	"���˻�����������������,����ΪĪ���»���ʷ����ǿ���սʿ.����û����,������\n"
    "��ͻ���Ī���°���������.\n"	
	);
    set("weapon_master",1);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("axe",100);
	set_skill("parry",100);
	set_skill("dodge",90);
        set("special_defense", (["all":30,"none":40,"monk":10,"scholar":10]) );
	set ("aim_difficulty",([ "vascular":35 , "weakest":20 ]) );
	set ("max_hp", 850);
	set ("hit_points", 850);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll",
         "valor"  :"@@ask_valor",
           ]) );
    
    set ("chat_chance", 25);
	set ("chat_output", ({
    "��������˵:Ҫ�����ұ��뱣���ʹ��İ�ȫ,�����ɱ�����˵ĳ�Ѩ��\n",
	    "��������˵:�����������������ǵ�,��֤������һ������(valor).\n"
	    }) ); 
	set ("att_chat_output", ({
	    "��������˵:���˵ĵ���,������\n",
	    }) );
	
	wield_weapon(Weapon"/axe03");
	equip_armor(Armour"/plate04");
	set ("cutknife", 5);
}

void ask_troll( object who )
{
        tell_object( who, 
          "����,�к�ǿ��������,���ǰ������Ѿ���������ս��������\n"
          "�������֪�����꾡������,�������ս���о��ҵĿ���(Karl)����\n"
          "�ܸ�����.\n");
      return ;        
}

void ask_valor(object who)
{
      object ob8;
      
      tell_object(who,
      "֤������һ�����ߵķ���������,����һֻ����(troll),Ȼ������Ķ����������.\n"
     );
     if( (int)(who->query_level())<15 ) {
         tell_object(who,"\n\n�������¿�����˵:������ĵȼ����������Ұ�!\n");
         return ;
      }
      if( !query("cutknife") )
      	write("��������˵: �Ѿ�û�и��С���ˣ��´ο����ɡ�\n");
      else {
      	ob8=new(Weapon"/cutknife");
      	ob8->move(who);
      	add("cutknife",-1);
      	write("�������¸���һ�Ѹ��С����\n");
      }
     return ;
}

int accept_item(object ob1,object ob2)
{
     object ob3;
     
     if (!ob2 || (int)(ob2->query("receive_trollear"))!=1) return 0;
     if ((int)(ob2->query("receive_trollear"))==1) {
        tell_object(ob1,
        "��������˵:\n"
        "�������Ѿ�֤�����������.\��\��\�������Щ����,Ϊʲ���һ�Ҫ��ȥð��\n"
        "�����ս��?��Ϊһ�������ѵ�������������.\n"
        "�ڿ�ӵ�\�,��������˵�еĺ��������ʿ( skeleton blackknight ),\n"
        "���ǵĳ�������ʹ�ð��˹�������ֻ�,������ʱ�Ĺ���Ī���¶���������\n"
        "�Ķ��Ӱ�����˹(Alaits),������һȺ��Ӣսʿ����������������ʨ�շ���\n"
        "�������.���������ǰȥ�Կ�����ʿ.������ȻĪ���¶���Ӣ�µ�ս��,��\n"
        "����������ʿ��Ҳû�г�����.\n"
        "������������,��ʱ�ĺ���ʿ�ƺ�������. �����Һ�ĳ�ε�������ɵĴ���\n"
        "Ԩ���������.ֻ�������ǰ������ʥ��ȴ�����˺ܴ����в, �����Ӱ���\n"
        "�빬͢ħ��ʦ���Ϊ�˶Կ����˼�˾�����������ĺڰ�ħ������\n"
        "�����о������������.ϣ�����ܹ���������.\n"
        );
       if( (int)(ob1->query_level())<15 ) {
         tell_object(ob1,"\n\n�������¿�����˵:������ĵȼ����������Ұ�!\n");
         return 1;
       }
       ob3=new(Object"/blackcard");
       ob3->set("someone_id",ob1->query("name"));
       ob3->move(ob1);
       tell_object(environment(),sprintf("�������¸�%sһ��֤���ļ�.\n",ob1->query("c_name")));
       tell_object(ob1,"�������֤��,�������궼��ɪ��(show),��������Խ����Ԩ.\n"); 
       ob2->remove();
       ob1->set_explore("deathland#33"); 
       return 1;
     }
}
