//
//  ViewController.swift
//  Tink
//
//  Created by Wonder Mac on 06/09/22.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var middleLabel: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        middleLabel.text = TestWrapper().sayWelcome() // get responce from cpp file
    }


}

