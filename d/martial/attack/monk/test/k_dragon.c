// angel
// Jun 4 1994

int query_need_fp()

{ 
    return 9;
}
int gonfu_level(object me)
{
        // ��������ֵ
        return (int)me->query("k-dragon");
        //                     ^^^^^^^^^^^^^^^^^^������
}


varargs int can_use(object me, object victim, object weapon)
{
        // ȷ����ʹ�������Ƿ���ȷ
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
        	  case "gonfu9"  : type = 9;  break;
        	  case "gonfu10"  : type = 10;  break;
        	  case "gonfu11"  : type = 11;  break;
        	  case "gonfu12"  : type = 12;  break;
        	  case "gonfu13"  : type = 13;  break;
        	  case "gonfu14"  : type = 14;  break;
        	  case "gonfu15"  : type = 15;  break;
        	  case "gonfu16"  : type = 16;  break;
        	  case "gonfu17"  : type = 17;  break;
        	  case "gonfu18"  : type = 18;  break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 18  ) {type++;}
        else {type =1;}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// ��ʽս��ѶϢ
string *attack_msg = ({




//                  ����͵��  ��������  
//                  ��Ӱ�ݺ�  ����ǧ��  ˫������   �����̡�
                   


        "%sһ�ơ������С�������%s", 
        "%s��������˫�ƣ���˫��ȡˮ������%s", 
        "%s���ָ���������һ�ơ����Ʋ��꡻����%s",
        "%sͻȻ��ס���Σ�һ�С���ͣ�Ԩ������%s",
        "%s����ǰ�ۣ�һ�С�����������ƿ���%s",
        "%s���λ���������һ�С���˪��������������%s",
        "%s�������϶���ǰ�ۣ�˲��ʹ�����轥�½�����ƿ���%s",
        "%s�������һ�У�����һ�ǡ�����󴨡�����%s",   
        "%s���ƻ��أ�����ͻȻʹ��һ�С�Ǳ�����á�����%s",   
        "%s˫ȭ����һ�С��𾪰������%s",
        "%s���Ƴ�צ��˫צʹ��������������ץ��%s",
        "%s����ͻȻ����һ����ʹ����������\β�����ƿ���%s",
        "%s������ɣ�һ�����ơ�ʱ����������������%s",
        "%s���Ƴ�ȭ��һ�ǡ��������������صĴ���%s",
        "%s�����ĳ�һ�ơ�ս���Ұ�����ƻֺ꣬����%s",
        "%s���һ����һ�ǡ������лڡ�Ю����ھ�����%s",
        "%s��Хһ��ʹ����ͻأ�����������籼��Ѹ�ٿ���%s",
        "%s��շ���ʹ����ǿһʽ���������졻˫�������������%s",


                     });



int *hits = ({ 65, 68, 71, 74, 77, 80, 83, 85,88,92,95,97,100,102,105,107,110,115 });
int *dams = ({ 47, 50, 53, 56, 59, 62, 64 ,66,68,70,74,76,78,80,85,87,90,99});



varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i,delta_dex;
        // �����ʵ���
        if( (type<1||type>18) ) return 0;
 
       // �����ʵ���ֵΪ �ٷ�֮��  ������/5 + 65~85 ��
        i =  gonfu_level(me)/4 + hits[type-1];
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        int i,delta_str;
        // ��͸�ʵ���
        if( (type<1||type>18) ) return 0;
        delta_str = (int)me->query_stat("str")-(int)victim->quert_stat("str");
        if (delta_str<0) { delta_str=0; } 
        i = gonfu_level(me)/2 +15 +random(20)+ delta_str/2 ;
        if(i<0) i=0;
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        // ��͸�ʵ���Ϊ�ٷ�֮��������/4 + ˫��������/2����������򲻼�
        return i;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        mixed ii,dam; 
        // ����������
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        if( (type<1||type>18) ) return 0;
        i = gonfu_level(me)/5+dams[type-1];
        // ����������Ϊ�ٷ�֮��  ������/6+ 11~18��
  
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( (type<1||type>18) ) return 0;
        a_msg = attack_msg[type-1];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"�����ǳ���ʱ�Ե���������ĸо�";}
        return a_msg;
}
