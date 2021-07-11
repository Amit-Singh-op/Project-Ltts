### TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H-01| All enemies are dead | Enemy count is zero and player is alive  | Return YOU_WIN | Return YOU_WIN | Scenario based |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L-01       | All enemies are not dead | Enemy count is not zero and player is dead | Return YOU_HIT_BY_AN_ENEMY | Return YOU_HIT_BY_AN_ENEMY | Scenario based |
|  L-02       | Shooting laser enemy | Laser enemy is killed | Return LASER_ENEMY_CANT_BE_KILLED_BY_PLAYERS_SHOT | Return LASER_ENEMY_CANT_BE_KILLED_BY_PLAYERS_SHOT | Scenario based  |
