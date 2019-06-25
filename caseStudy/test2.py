import sys, os
sys.path.append(os.path.join(os.getcwd(), "src"))
from utility import visualize_PRT_results, combine_reports, summarize_matrix, summarize_report

SDK_PATH = os.path.join(os.getcwd(), "install", "bin")
sys.path.append(SDK_PATH)

import pyprt
import numpy as np
#help(p)

VAL = pyprt.print_val(407)
print("\nTest Function: it should print 407.")
print(VAL)

CS_FOLDER = os.getcwd()
def asset_file(filename):
    return os.path.join(CS_FOLDER, "caseStudy", filename)

print("\nInitializing PRT.")
pyprt.initialize_prt(SDK_PATH)

if not pyprt.is_prt_initialized():
    raise Exception("PRT is not initialized")

shapeGeo = asset_file("candler_footprint.obj")
rpk = asset_file("Building_From_Footprint.rpk")
attrs = ["ruleFile:string=rules/Buildings/Building_From_Footprint.cgb", "startRule:string=Default$Generate", "Reporting:string=All"]

mod = pyprt.ModelGenerator(shapeGeo)
models = mod.generate_model(rpk, attrs)

visualize_PRT_results(models)

pyprt.shutdown_prt()
print("\nShutdown PRT.")