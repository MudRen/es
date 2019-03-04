inherit WEAPON;

void create()
{
    set_name("Shadow dagger","ҹӰ��");
    add("id",({"dagger"}) );
    set_short("ҹӰ��");
    set_long(@AAA
����һ��ɢ����а����Ϣ��ذ�ף�������ֵ�����������ȴ��
�����󵶣�
AAA
       );
    set("unit","��");
    set("weapon_class",30);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",27);
    set("weight",100);
    set("value",({110,"gold"}));
//    set("hit_func","dagger_damage");
    set("special_msg","  .\n\n");
    set("special_c_msg"," ���ճ����ߵ�а������� ������\n\n"
        "���а���������Ϊһ�Ѿ��д�����˵�Ҫ��������\n");
}

int dagger_damage(object victim,int damage)
{
    object holder;
    int my_kar,dam;
    string c_msg,msg;
    if( !victim ) return 0;
      if( !(holder = environment(this_object())) || !living(holder) ) return 0;
        if( (int)holder->query("alignment") > -2000 ) return 0;

        my_kar = (int)holder->query_stat("kar");
        dam = 30 ; 
        if( random(20) > my_kar/5 )
                return 0;
        else {
                msg = (string)query("special_msg");
                c_msg = (string)query("special_c_msg");
                victim->receive_damage( dam );
                victim->set("last_attacker", holder );
                if( !c_msg ) c_msg = msg;
                if( !msg ) return 0;
                tell_object( holder, can_read_chinese(holder)?
                        "\n���"+query("c_name")+c_msg+"\n":
                        "\nYour "+query("name")+msg+"\n" );
                tell_room( environment(holder), ({
                        holder->query("cap_name") + "'s "+query("name")+msg+"\n",
                        holder->query("c_cap_name") + "��"+query("c_name")+c_msg+"\n"}),
                        holder );
                return dam;
     }
        
}       

