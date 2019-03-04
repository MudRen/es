#include "/u/m/moon/moon.h"
inherit WEAPON;
int tag;
string color();
void create()
{
    seteuid(getuid());
    set_name("Color Sword","����׷�½�");
    set_short( "@@short" );
    add("id", ({"sword"}));
    set_long("    ����ȫ�ܵĴ�����--"+set_color("CREATIVE","HIR")+"��ר�ñ���, \n"+
             "������ʱ�䲻�ϱ任��ɫ����˵�ϵ۾��������С�\n" );
    set("unit","��");
    set("weapon_class",10);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",1);
//    set("prevent_drop",1);
    set("value",({10000,"silver"}) );
    set( "hit_func", "weapon_hit" );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
    tag=0;
}

void daemon_wield()
{

    object p, helm, plate, arms, hands, leggings, feet;
    string s;
    p = environment(this_object());
    s = p->query("c_name");

  if( (string)this_player()->query("name")=="creative") {
    set("weapon_class",50);
    set("prevent_drop",1);
    set("min_damage",100);
    set("max_damage",200);
    set("extra_look","@@change_color");
    if (p->query("armor/head") || p->query("armor/body") 
       || p->query("armor/arms") || p->query("armor/hands") 
       || p->query("armor/legs") || p->query("armor/feet"))
    {
          tell_object(p, "�����ж��������׷�½����߳�ͻ�Ļ��߲���װ������׷�½���\n");
          ::unwield(0);
          return;
    }

    tell_room(environment(p), set_color(
    sprintf("\n%s������׷�½��߸߾��𣬴��һ���������ǲ���սʤ�� ����\n\n", 
    p->query("c_name")), "HIR"), p);
    tell_object(p, set_color(
    "\n�㽫����׷�½��߸߾��𣬴��һ���������ǲ���սʤ�� ����\n\n", "HIR"));

    tell_room(environment(p), set_color(
    sprintf("\n����׷�½���Ӧ��%s���������û���һ�׿��ס�\n\n", 
    p->query("c_name")), "HIR"), p);

    tell_object(p, set_color("����׷�½���Ӧ������������û���һ�׿��ס�\n\n", "HIR"));

    plate = new(ARM"plate");
    plate->move(p);
    plate->equip(1);
    tell_object(p, "��˳���ش��ϴ����߼ס�\n");
    tell_room(environment(p), s+"˳���ش��ϴ����߼ס�\n", p);
    p->calc_armor_class();

    helm = new(ARM"helm");
    helm->move(p);
    helm->equip(1);
    tell_object(p, "��˳���ش��ϴ����߿���\n");
    tell_room(environment(p), s+"˳���ش��ϴ����߿���\n", p);
    p->calc_armor_class();

    arms = new(ARM"arms");
    arms->move(p);
    arms->equip(1);
    tell_object(p, "��˳���ش��ϴ����߻��ۡ�\n");
    tell_room(environment(p), s+"˳���ش��ϴ����߻��ۡ�\n", p);
    p->calc_armor_class();

    leggings = new(ARM"leggings");
    leggings->move(p);
    leggings->equip(1);
    tell_object(p, "��˳���ش��ϴ����߻��衣\n");
    tell_room(environment(p), s+"˳���ش��ϴ����߻��衣\n", p);
    p->calc_armor_class();

    hands = new(ARM"hands");
    hands->move(p);
    hands->equip(1);
    tell_object(p, "��˳���ش��ϴ������֡�\n");
    tell_room(environment(p), s+"˳���ش��ϴ������֡�\n", p);
    p->calc_armor_class();

    feet = new(ARM"feet");
    feet->move(p);
    feet->equip(1);
    tell_object(p, "��˳���ش��ϴ�����Ь��\n");
    tell_room(environment(p), s+"˳���ش��ϴ�����Ь��\n", p);
    p->calc_armor_class();
    set("prevent_drop",1);

   }
   else set("prevent_drop",0);
}

void daemon_unwield()
{
        object holder ;
        if ( !holder = environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"ͻȻ, �����еĽ��û����ϵ�ȽȽ�������ȥ...\n");
         tell_room( environment(this_player()),
           "ͻȻ"+this_player()->query("c_name")+"���еĽ��û����ϵ�ȽȽ�������ȥ....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
    set("min_damage",0);
    set("max_damage",5);
    delete("extra_look");
    set("weapon_class",10);
    return ;
    }
}
void unwield(int silent)
{
    object p, firstwep, secondwep, helm, plate, arms, leggings, hands, feet;

    p = environment(this_object());

   if( (string)this_player()->query("name")=="moon") {

    if (p->query("armor/body"))
    {
        plate = p->query("armor/body");
        plate->remove();
    }

    if (p->query("armor/head"))
        {
            helm = p->query("armor/head");
            helm->remove();
        }
    if (p->query("armor/arms"))
       {
            arms = p->query("armor/arms");
            arms->remove();
        }
    if (p->query("armor/feet"))
        {
            feet = p->query("armor/feet");
            feet->remove();
        }
    if (p->query("armor/legs"))
        {
            leggings = p->query("armor/legs");
            leggings->remove();
        }
    if (p->query("armor/hands"))
        {
            hands = p->query("armor/hands");
            hands->remove();
        }
    }

    set("prevent_drop", 0);

    ::unwield(0);
}


int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
if (!((string)owner->query("name")=="creative")){
     tell_object( owner,
     "\n�����еĽ��û����ϵۣ���������һЦ���� ! ��ɲ������ҵ�����Ŷ..\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n�����еĽ��û����ϵۣ� ��"+victim->query("c_name")+"��ȥ\n\n" );
       tell_object( victim, "\n" +
          owner->query("c_name") + "���߲���ͻȻ�û���"+
          set_color("�ϵ�",color())+"������ȻһЦ" +
          ", ������Ƚŷ���������!\n\n" );
       tell_room( environment(owner),
     "\n" + owner->query("c_name") + 
    "���߲���ͻȻ�û����ϵ���" + victim->query("c_name") + 
    "��ȥ!\n\n" , ({ victim, owner }) );
       victim->receive_damage(250);
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
        }
}


string color()
{
    string clr;
    tag++;
    switch (tag)
    {
       case 1:
           clr="HIR";
           break;
       case 2:
           clr="HIG";
           break;
       case 3:
           clr="HIY";
           break;
       case 4:
           clr="HIB";
           break;
       case 5:
           clr="HIM";
           break;
       case 6:
           clr="HIC";
           break;
       default:
           clr="HIW";
           tag=0;
     }
     return clr;
}
/*           
string name()
{
    return set_color("Color Sword",color());
}
*/         
string short()
{
    return set_color("����׷�½�",color());
}
string change_color()
{
    return set_color("$N����������һ���߲ʵ���...\n",color());
}

