
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	seteuid(getuid());
	set_name( "homdlaser", "�궼��ɪ" );
	set_short( "a dwarf experienced miner homdlaser", "����ר�ҿ󹤺궼��ɪ" );
	set_long(
	" Dwarf experienced miner,homdlaser is the manager for the factory,and he knows \n"
	"many knowledge.So cart can get the best effivelity.To talk with him,maybe you get\n"
	"some messages.\n",
	"����ר�ҿ󹤺궼��ɪ,�Ѿ��������󳧺ܶ�����.���Ҷ�춰��˿��(mine)��ĵ�\n"
	"�ε���ǳ��˽�.���԰����˿�(cart)�����ĵ����·���������Ч��.����̸̸\n"
	"\��\��\��������벻�����ջ�.\n"
	);

    set("alignment",400 );
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",88);
	set_skill("dodge",88);
	set ("max_hp", 770);
	set ("hit_points", 770);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon(35,22,33);
	set_natural_armor(70,35);
    set ("weight", 400);
    set( "inquiry", ([
         "cart" : "@@ask_cart",
         "carts": "@@ask_cart",
         "valor": "@@ask_valor",
         "mine" : "@@ask_mine",
           ]) );
    set("echo_valor",1);
    set ("chat_chance", 7);
	set ("chat_output", ({
	    "Homdlas says: Notice safety\n",
	    "�궼��˹˵:ע�ⰲȫ,���ӳ�����Σ��.\n",
	    "Homdlas says:if you want to help us,please prove you are a valor first.\n",
	    "�궼��˹˵:�����������������ǵ�,��֤������һ������(valor).\n"
	    }) ); 
}

void ask_cart( object who )
{
     tell_object(who ,can_read_chinese(who) ?
     "һ����Ĭ��˹�������˺�,ϣ˹������(Cisklyph),���������������������������,\n"
     "�������ǽ����˺������Ŀ��������ϵͳ.����������˿�,����һ���ܸ��ӵĻ���\n"
     ",��������Ҳ���Ǻ��˽�,ֻ֪�����ܺܿ��ٵ��ڹ�����ƶ�.�����˿󳵵�ȷ������\n"
     "�ǵĲɿ��ٶȼӿ���.\n"
     :
     " \n"
     );
}
void ask_mine(object who)
{
    tell_object(who ,can_read_chinese(who) ?
    "���,һ�������ƽ�ĵط�,����Ҳ������Σ��������\n"
    "���ǰ����Ѿ������˴󲿷ݵĵط�,���ǻ���һЩ�ر�Σ�յĵط�,�Ѿ������Ƿ�ס.\n"
    "��ʹ����̽�������ܸߵ���Ȥ,������Ĳ���ȥ�ھ��!ͨ���ڹ���ľ�ͷ����û\n"
    "��һ��������(���˿�ͣס�Ļ���),����\��\��\�㽫�������Ƕ����д����ĲƸ���\n"
    "������.��ȻҲ�����͵Ĺ����ڵ�����\n"
    :
    "\n"
    );
}
void ask_troll( object who )
{
        tell_object( who, can_read_chinese(who) ?
          "����,�к�ǿ��������,���ǰ������Ѿ���������ս��������\n"
          "�������֪�����꾡������,�������ս���о��ҵĿ���(Karl)����\n"
          "�ܸ�����.\n"
          :
          "troll\n" );
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,can_read_chinese(who) ?
      "ȥ�һ��������ӳ���������,������������꾡������\n "
      :
      " \n"
     );
      return ;
}

int echo_valor(object ob1,object ob2)
{
     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
     if ((int)(ob2->query("echo_quest_card"))==1) {
        if( ob1->query("name")!=ob2->query("someone_id") )
          {
          tell_object(ob1,
          "�����⿨Ƭ�ǷǷ�������.�����Ҳ��ܰ����������.\n"
           );
          }
        else {
        tell_object(ob1,can_read_chinese(ob1) ?
        "�������.�궼��˹˵\n"
        "�궼��˹���㾴��.\n"
        "�������Ѿ�֤�����������.���ǵ�ʥ���������˺ܴ����в,���������ʿ\n"
        "�Ĺ���ʹ��Ŀǰ��ʥ���о�����ħ���İ���������һ����Ѫ��ȫ���� .ϣ\n"
        "����ĳ����ܰ�������.\n"
        :
        " \n"
        );
       call_out("cart_open",2,this_object());
      // ob2->move(ob1);
      // tell_object(environment(),"�궼��˹�ѿ�Ƭ����"+ob1->query("c_short")+"\n");
          }
     }     
     return 1;  
}

int cart_open(object ob1)
{
    object ob3,ob4;
    
    switch ((int)environment(ob1)->query("open_cart"))
      {
      case 1:   
         ob3=new(Mine"/obj_cart");
         ob4=new(Mine"/room_cart");
         ob3->set_roomcart(ob4);
         ob4->set_objcart(ob3);
         ob3->move(environment(ob1));
         tell_room(environment(ob1),"�궼��˹��ϣ˹�������˿󳵿��˳���.\n");
         environment(ob1)->set("open_cart",2);
         break;
      case 2:
         tell_room(environment(ob1),"�˿��Ѿ���������.\n");
         break ; 
     
      }     
    return 1;
}
