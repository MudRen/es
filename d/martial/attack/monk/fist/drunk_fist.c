// �书����ȭ�� part2
// angel
// Jun 4 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 4;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type,i;
	string last;
        if( weapon ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "gonfu1"  : type = 1;  break;
        	  case "gonfu2"  : type = 2;  break;
        	  case "gonfu3"  : type = 3;  break;
        	  case "gonfu4"  : type = 4;  break;
        	  case "gonfu5"  : type = 5;  break;
        	  case "gonfu6"  : type = 6;  break;
        	  case "gonfu7"  : type = 7;  break;
        	  case "gonfu8"  : type = 8;  break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 8 && random(8) > 2 ) {type++;}
        else {type =1+random(8);}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// ��ʽս��ѶϢ
string *attack_msg = ({

        "%s����һЦ��ʹ�������ɹã������׾����������Ų�Ʈ�ƣ�����%s", 
        "%sһ��һ�գ�ͻȻһ�С����������ϥײ���桻����%s",
        "%sһ�С������ӣ���������������%s������������״����Ϊ����",
        "%sʹ�������ɺͣ����ᾴ�������ơ����ƻֺ꣬����%s",
        "%s���ζ���������һ�С������룬���������Ķ���ײ��%s",
        "%s���Ź��ϣ�����ױ���������һ����������%s",
        "%s���Ŷ�����һ�ǡ��ܹ��ˣ����˾�������ۡ�˫�ַ��ٿ���%s",
        "%s���һ��������������������ǧ����˫ȭ�����������%s",
                     });



int *hits = ({ 65, 78, 60, 76, 67, 75, 70, 75 });
int *dams = ({ 14, 16, 18, 20, 23, 25, 28, 30 });



varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() ) return -5; 
        return   (hits[type-1]*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() ) return -5; 
        return ((30 + random(11))*monk_modify(victim)/100) ;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
       if( (type<1||type>8) ) return 0;
       if( (int)me->query("force_points") < query_need_fp() )	return -5; 
       me->add("force_points", -query_need_fp());
       return (dams[type-1]*monk_modify(victim)/100); 
}

varargs string query_attack_msg(object me, object victim, int type)
{
        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(8)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(8)];
}
