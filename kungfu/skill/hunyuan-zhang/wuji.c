// wuji.c 混元无极
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「混元无极」"

int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	fskill = "zixia-shengong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用"PNAME"！\n");
 
	msg = HIC "$N"HIC"潜运「混元无极」，双拳挟着隐隐的风雷之声向$n"HIC"击去。\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-100);
		msg =HIG"$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
		neili_wound = 100 + random(skill);
		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_wound("qi", qi_wound,me);

		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		target->add("neili", -neili_wound);

		target->start_busy(2);
		me->start_busy(1+random(2));
	}
	else
	{
		msg = HIG "只见$n"HIG"不慌不忙，轻轻一闪，躲过了$N"HIG"的必杀一击！\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		迟滞对方出手

	出手要求：
		紫霞神功60级
		混元掌60级
		内力150
HELP
	);
	return 1;
}

