inherit WEAPON;

void create()
{
    set_name( "icy","����" );
    set_short( "����" );
    set_long(@C_LONG
����Ʈѩ�ɼ��İ�����ߣ�է��ֻ��һö���꺮������һ������Σ�գ�
�ɼ��ͻ�����û���ǿ���Ĺ���������
C_LONG
            );
    set("unit","ö");
    set("weapon_class",50);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",1);
    set("prevent_drop",1);
    set("value",({1,"silver"}) );
    set( "hit_func", "weapon_hit" );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("name")=="snow") {
    set("prevent_drop",1);
    set("min_damage",30);
    set("max_damage",100);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n����һ���������Ǻ��⽣���ѳ����������ϣ�\n\n"
       ,"HIW") );
    tell_room( environment(this_player()),set_color(
       "\n"+"ͻȻ����һ�󺮷磬"+this_player()->query("c_name")+
       "�����Ѷ���һ�Ѻ��������ı�����\n\n"
       ,"HIW"),this_player() );
    set_name("icy sword","���Ǻ��⽣");
    add("id",({"icy","sword"}) );
    set_short("���Ǻ��⽣");
    return;
    }
}

void daemon_unwield()
{
        object holder ;
        if ( !holder = environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"ͻȻ��ǿ��һ��,�����еı��Ǻ��⽣����ʧ������....\n");
         tell_room( environment(this_player()),
           "ͻȻ����һ�󺮷�"+this_player()->query("c_name")+"���еı��Ǻ��⽣����ʧ��....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
    set("min_damage",0);
    set("max_damage",5);
    set("prevent_drop",1);
    delete("extra_look");
    set_name("icy","����");
    set_short("����");
    return ;
    }
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
   if (!((string)owner->query("name")=="snow")){
     tell_object( owner,
     "\n�����еı�������һ���������������� ! �㲻�����ҵ����ˡ�\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n�㽫һ����������춱��Ǻ��⽣, ��ͻȻ����һ������"+victim->query("c_name"
)+"��ȥ\n\n" );
       tell_object( victim, "\n" +
          owner->query("c_name") + "�ĺ��⽣ͻȻ����һ��������Ϯ��!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "�ı���ͻȻ��" + victim->query("c_name") + "��
��һ����!\n\n"
         , ({ victim, owner }) );
       victim->receive_damage(1000);
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
        }
}



string color()
{
    return set_color("$N������������һ����������γɵİ�ɫ����...\n","hiw");
}
