// kitgonfu.c
// This is a attack skill that is only available for wizards.

varargs int can_use(object me, object victim, object weapon)
{
		int type;
		string last;
        if( weapon ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "kitgonfu1"  : type = 1;  break;
        	  case "kitgonfu2"  : type = 2;  break;
        	  case "kitgonfu3"  : type = 3;  break;
        	  case "kitgonfu4"  : type = 4;  break;
        	  case "kitgonfu5"  : type = 5;  break;
        	  case "kitgonfu6"  : type = 6;  break;
        	  case "kitgonfu7"  : type = 7;  break;
        	  case "kitgonfu8"  : type = 8;  break;
        	  case "kitgonfu9"  : type = 9;  break;
        	  case "kitgonfu10" : type = 10; break;
        	  case "kitgonfu11" : type = 11; break;
        	  case "kitgonfu12" : type = 12; break;
        	  case "kitgonfu13" : type = 13; break;
        	  case "kitgonfu14" : type = 14; break;
        	  case "kitgonfu15" : type = 15; break;
        	  case "kitgonfu16" : type = 16; break;
        	  case "kitgonfu17" : type = 17; break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 17 && random(type+100) > type ) type++;
        else type = 1;
        me->set_temp("last_attack_skill", ("kitgonfu"+type));
        return type;
}

int query_need_fp()
{
	return 0;
}

string *attack_msg = ({
        "%sʩչ��Ȼ�������С��ľ�������һʽ����Ȼ�ػ���%s",
        "%s������ʩչ��Ȼ�������С�������졻һʽ����%sһ�ƻ�ȥ",
        "%s�Ե���ʩչ��Ȼ�������С��������С�һ�У���%s��Ȼ��ȥ",
        "%s�����ָ�춱���ʩչ��Ȼ�������С������ˮ��һ�У�һ�ƻ���%s",
        "%sʩչ��Ȼ�������С��ǡ��չȡ�һ�У���%s��Ȼ��ȥ",
        "%s������ʩչ��Ȼ�������С��������ġ�һʽ����Ȼ�ػ���%s",
        "%s�Ե���ʩչ��Ȼ�������С��С����⡻һʽ����%sһ�ƻ�ȥ",
        "%s�����ָ�춱���ʩչ��Ȼ�������С�������ʩ��һ�У���%s��Ȼ��ȥ",
        "%sʩչ��Ȼ�������С�������ʳ��һ�У�һ�ƻ���%s",
        "%s������ʩչ��Ȼ�������С�����ֻӰ��һ�У�һ�ƻ���%s",
        "%s�Ե���ʩչ��Ȼ�������С�����������һʽ����Ȼ�ػ���%s",
        "%s�����ָ�춱���ʩչ��Ȼ�������С����񲻰���һʽ����%sһ�ƻ�ȥ",
        "%sʩչ��Ȼ�������С���;ĩ·��һ�У���%s��Ȼ��ȥ",
        "%s������ʩչ��Ȼ�������С�������ɫ��һ�У�һ�ƻ���%s",
        "%s�Ե���ʩչ��Ȼ�������С�����Ƿǡ�һʽ����%sһ�ƻ�ȥ",
        "%s�����ָ�춱���ʩչ��Ȼ�������С�����ľ����һʽ����Ȼ�ػ���%s",
        "%s������ʩչ��Ȼ�������С��겻���᡻һ�У���%s��Ȼ��ȥ",
});

int *hits = ({ 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 });
int	*penes = ({ 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 });
int	*dams = ({ 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 });

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return hits[type-1];
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return penes[type-1];
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -5;
        me->add("force_points", -query_need_fp());
        return dams[type-1];
}

varargs string query_attack_msg(object me, object victim, int type)
{
		if( type < 1 || type > 17 ) return 0;
        return attack_msg[(type-1)];
}
