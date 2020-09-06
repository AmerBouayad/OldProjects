//
//  ViewController.swift
//  Ar3DWatchTest
//
//  Created by abo on 12/03/2020.
//  Copyright © 2020 abo. All rights reserved.
//

import UIKit
import ARKit

class ViewController: UIViewController, ARSCNViewDelegate {
    
    @IBOutlet weak var sceneView: ARSCNView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        sceneView.delegate = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        guard let referenceImages = ARReferenceImage.referenceImages(inGroupNamed: "AR Resources", bundle: nil) else {
            fatalError("Missing expected asset catalag ressources.")
        }
        
        let configuration = ARImageTrackingConfiguration()
        configuration.trackingImages = referenceImages
        configuration.maximumNumberOfTrackedImages = 1
        sceneView.session.run(configuration)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        sceneView.session.pause()
    }
    
    func renderer(_ renderer: SCNSceneRenderer, didAdd node: SCNNode, for anchor: ARAnchor) {
        DispatchQueue.main.async {
            
            if let imageAnchor = anchor as? ARImageAnchor {
                let referenceImage = imageAnchor.referenceImage
                
                // Create a plane to visualize the initial position of the detected image.
                let plane = SCNPlane(width: referenceImage.physicalSize.width,
                                     height: referenceImage.physicalSize.height)
                
                let planeNode = SCNNode(geometry: plane)
                planeNode.geometry?.firstMaterial?.diffuse.contents = UIColor(white: 1, alpha: 0)
                
                planeNode.eulerAngles.x = -.pi / 2
                
                let watchScene = SCNScene(named: "art.scnassets/AudemarsPiguet_OBJ_OBJ_Audemars Piguet.obj")!
                let watchNode = watchScene.rootNode.childNodes.first!
                watchNode.position = SCNVector3Zero
                watchNode.position.z = 0.1
                watchNode.scale = SCNVector3(0.0015, 0.0015, 0.0015)
                
                let material = SCNMaterial()
                material.diffuse.contents = UIImage(named: "art.scnassets/Texture/AudemarsPiguet_OBJ_Texture_AP_diffuse.jpg")
                material.normal.contents = UIImage(named: "art.scnassets/Texture/AudemarsPiguet_OBJ_Texture_AP_normal.jpg")
                
                watchNode.geometry?.materials = [material]
                
                planeNode.addChildNode(watchNode)
                // Add the plane visualization to the scene.
                node.addChildNode(planeNode)
            }
        }
    }
    
    
}

